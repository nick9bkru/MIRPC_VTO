#ifndef STYLE_H
#define STYLE_H
#include <QString>
//"color: #006aff;"

//                "height: 30px;"
/**


qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0.0 #f5f9ff, stop : 0.5 #c7dfff, stop : 0.55 #afd2ff, stop : 1.0 #c0dbff);"
*/
const QString QPushButtonStyle("QPushButton {"
                        "background-color: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0.0#f5f9ff,"
                               "stop : 0.5 #c7dfff, stop:0.55#afd2ff,stop:1.0#c0dbff);"
                        "border-radius: 8px;"
                        "border: 2px solid #6593cf;"
                      "border-color: navy;"
             " }");
const QString QLabelStyle("QLabel {"
                          "background: qlineargradient(x1 : 0, y1 : 0, x2 : 0, y2 : 1, stop : 0.0 #f5f9ff,"
                                         "stop : 0.5 #c7dfff, stop : 0.55 #afd2ff, stop : 1.0 #c0dbff);"
             " }");
const QString QFrameStyle(".QFrame {"
                         "border: 2px solid #0800f2;"
             " }");
#endif // STYLE_H
