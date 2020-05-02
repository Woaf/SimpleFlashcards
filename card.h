#ifndef CARD_H
#define CARD_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include <vector>
#include <utility>
#include <string>

class Card : public QMainWindow
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = nullptr);

private: // METHODS
    void InitializeWordList ();
    void DisplayWord ();
    void ReadDictionaryFromFile ();

private:
    bool showKey;
    size_t index;
    std::vector<std::pair<std::string, std::string>> dictionary;

    QLabel*      enumerator;
    QLabel*      text;
    QHBoxLayout* navigationHolder;
    QVBoxLayout* mainLayout;
    QPushButton* flipButton;
    QPushButton* prevButton;
    QPushButton* nextButton;

    QWidget* mainWidget;

signals:

private slots:
    void FlipCard ();
    void PrevCard ();
    void NextCard ();
};

#endif // CARD_H
