#   _    _ _______   __  __ _____ _____ _____   ____  _   _
#  | |  | |__   __| |  \/  |_   _/ ____|  __ \ / __ \| \ | |
#  | |__| |  | |    | \  / | | || |    | |__) | |  | |  \| |
#  |  __  |  | |    | |\/| | | || |    |  _  /| |  | | . ` |
#  | |  | |  | |    | |  | |_| || |____| | \ \| |__| | |\  |
#  |_|  |_|  |_|    |_|  |_|_____\_____|_|  \_\\____/|_| \_|
#  =================== Advanced R&D ========================

#  Copyright (c) 2023 HT Micron Semicondutors S.A.
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#  http://www.apache.org/licenses/LICENSE-2.0
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

# file: ittapp.py
# brief: ittchip Example backend. Comunicates with PPI board.
# author: Matheus Zorzeto
# link: https://github.com/htmicron
# version: 1
# date: April 26, 2024

# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'front.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(261, 297)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.Button1 = QtWidgets.QPushButton(self.centralwidget)
        self.Button1.setGeometry(QtCore.QRect(40, 140, 181, 81))
        self.Button1.setObjectName("Button1")
        self.lcd1 = QtWidgets.QLCDNumber(self.centralwidget)
        self.lcd1.setGeometry(QtCore.QRect(40, 60, 181, 61))
        self.lcd1.setSegmentStyle(QtWidgets.QLCDNumber.Filled)
        self.lcd1.setObjectName("lcd1")
        self.label1 = QtWidgets.QLabel(self.centralwidget)
        self.label1.setGeometry(QtCore.QRect(230, 90, 16, 31))
        font = QtGui.QFont()
        font.setPointSize(14)
        self.label1.setFont(font)
        self.label1.setObjectName("label1")
        self.label2 = QtWidgets.QLabel(self.centralwidget)
        self.label2.setGeometry(QtCore.QRect(40, 20, 161, 31))
        font = QtGui.QFont()
        font.setPointSize(14)
        self.label2.setFont(font)
        self.label2.setObjectName("label2")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 261, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.Button1.setText(_translate("MainWindow", "LED OFF"))
        self.label1.setText(_translate("MainWindow", "C"))
        self.label2.setText(_translate("MainWindow", "Temperature:"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
