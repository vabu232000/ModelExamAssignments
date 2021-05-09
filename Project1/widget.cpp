#include "widget.h"
#include<QTextEdit>
#include<QPushButton>
#include<QDebug>
#include<QLabel>
#include<QColorDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//TO CREATE A FONT

   QFont labelFont("Times",20,QFont::Bold);

//TO CREATE A LABEL

   QLabel *mLabel=new QLabel("This is My Sentence",this);

//SET THE FONT TO LABEL

   mLabel->setFont(labelFont);

//MOVE THE LABEL

   mLabel->move(100,25);

//TO APPLY COLOR TO LABEL AND BACKGROUND COLOR TO LABEL

   QPalette label;

   label.setColor(QPalette::Window,Qt::yellow);

   label.setColor(QPalette::WindowText,Qt::red);

   mLabel->setAutoFillBackground(true);

   mLabel->setPalette(label);

  // Create a TextEdit by ,

    QTextEdit *text=new QTextEdit(this);

    text->move(70,55);

    connect(text,&QTextEdit::textChanged,[=](){

    qDebug()<<"Text Changed"; });

  //  Create a PushButton for cut button by,

     QPushButton *cut=new QPushButton("cut",this);

     cut->setMinimumSize(50,25);

     cut->move(10,250);

     connect(cut,&QPushButton::clicked,[=](){

      text->cut(); });

     //Create pushbutton for copy button by,

     QPushButton *copy=new QPushButton("copy",this);

      copy->setMinimumSize(50,25);

      copy->move(110,250);

      connect(copy,&QPushButton::clicked,[=](){

       text->copy(); });

      //Create pushbutton for paste button by,

      QPushButton *paste=new QPushButton("paste",this);

       paste->setMinimumSize(50,25);

       paste->move(210,250);

       connect(paste,&QPushButton::clicked,[=](){

        text->paste(); });


       //Create pushbutton for undo button by,

       QPushButton *undo=new QPushButton("undo",this);

        undo->setMinimumSize(50,25);

        undo->move(10,280);

        connect(undo,&QPushButton::clicked,[=](){

         text->undo(); });

        //Create pushbutton for redo button by,

        QPushButton *redo=new QPushButton("redo",this);

         redo->setMinimumSize(50,25);

         redo->move(110,280);

         connect(redo,&QPushButton::clicked,[=](){

          text->redo(); });

     QPushButton *html=new QPushButton("HTML",this);

      html->setMinimumSize(100,25);

      html->move(120,310);

      connect(html,&QPushButton::clicked,[=](){

       text->setHtml("<h1>Title</h1><p>Three districts:</br> <ul><li>X</li><li>Y</li><li>Z</li></ul></p>");
      });
}

Widget::~Widget()
{
}

