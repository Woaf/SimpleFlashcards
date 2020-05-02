#include "card.h"

#include <fstream>

Card::Card(QWidget *parent) :
    QMainWindow         (parent),
    showKey             (true),
    index               (0),
    enumerator          (new QLabel),
    text                (new QLabel),
    navigationHolder    (new QHBoxLayout),
    mainLayout          (new QVBoxLayout),
    flipButton          (new QPushButton ("Flip (see definition)")),
    prevButton          (new QPushButton ("Previous")),
    nextButton          (new QPushButton ("Next")),
    mainWidget          (new QWidget)
{
    this->setFixedSize (550, 250);

    enumerator->setAlignment (Qt::AlignLeft);
    enumerator->setText (QString::number (index+1));

    mainLayout->addWidget (enumerator);

    text->setFont (QFont ("Arial", 20));
    text->setAlignment (Qt::AlignCenter);
    text->setMinimumHeight (150);

    navigationHolder->addWidget (prevButton);
    navigationHolder->addWidget (nextButton);

    mainLayout->addWidget (text);
    mainLayout->addWidget (flipButton);
    mainLayout->addLayout (navigationHolder);

    connect (flipButton, SIGNAL (pressed ()), this, SLOT (FlipCard ()));
    connect (prevButton, SIGNAL (pressed ()), this, SLOT (PrevCard ()));
    connect (nextButton, SIGNAL (pressed ()), this, SLOT (NextCard ()));

    mainWidget->setLayout (mainLayout);
    setCentralWidget (mainWidget);

    InitializeWordList ();
    DisplayWord ();
}

void Card::ReadDictionaryFromFile () {
    std::fstream dictFile;

    QString text = QFileDialog::getOpenFileName(this,
                                                tr("Open dictionary"),
                                                nullptr,
                                                tr("Text files (*.txt)"));

    dictFile.open (text.toStdString());

    if (!dictFile.is_open ()) {
        QMessageBox::warning (nullptr,
                              "File not found!",
                              "Dictinary file not found!\nPlease make sure you have 'dict.txt' in your program directory.");
        return;
    }

    while (!dictFile.eof ())
    {
        std::string fst;
        std::string snd;

        dictFile >> fst;
        dictFile >> snd;

        dictionary.emplace_back (std::make_pair (fst, snd));
    }
}

void Card::InitializeWordList()
{
    ReadDictionaryFromFile ();
    // MIX WORDS (LATER MAYBE)
}

void Card::DisplayWord()
{

    showKey = true;
    if (!dictionary.empty ()) {
        enumerator->setText (QString::number (index % dictionary.size() + 1) + "/" + QString::number (dictionary.size()));
        text->setText (QString (dictionary.at (index % dictionary.size()).first.c_str ()));
        flipButton->setText ("Flip (see definition)");
    }
}

void Card::FlipCard()
{
    if (!dictionary.empty ()) {
        if (!showKey) {
            text->setText (QString (dictionary.at (index % dictionary.size()).first.c_str ()));
            flipButton->setText ("Flip (see definition)");
        } else {
            text->setText (QString (dictionary.at (index % dictionary.size()).second.c_str ()));
            flipButton->setText ("Flip (see original)");
        }
        showKey = !showKey;
    }
}

void Card::PrevCard()
{
    if (index - 1 == std::numeric_limits<size_t>::max ()) {
        index = dictionary.size () - 1;
    } else {
        index--;
    }
    DisplayWord ();
}

void Card::NextCard()
{
    if (index + 1 == dictionary.size ()) {
        index = 0;
    } else {
        index++;
    }
    DisplayWord ();
}
