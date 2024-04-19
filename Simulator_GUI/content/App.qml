// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.5
import Simulator_GUI

Window {
    width: mainScreen.width
    height: mainScreen.height

    visible: true
    title: "Simulator_GUI"

    Screen01 {
        id: mainScreen
        x: 17
        y: 0

        Rectangle {
            id: rectangle
            x: 533
            y: 330
            width: 96
            height: 126
            color: "#9f9f9f"
        }

        Rectangle {
            id: rectangle1
            x: 784
            y: 403
            width: 46
            height: 53
            color: "#999999"
        }

        Rectangle {
            id: rectangle2
            x: 607
            y: 488
            width: 111
            height: 9
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle3
            x: 719
            y: 389
            width: 9
            height: 108
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle4
            x: 768
            y: 330
            width: 9
            height: 108
            color: "#ffffff"
            rotation: -269.967
        }

        Rectangle {
            id: rectangle5
            x: 815
            y: 379
            width: 11
            height: 24
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle6
            x: 406
            y: 464
            width: 76
            height: 33
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle7
            x: 568
            y: 465
            width: 27
            height: 23
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle8
            x: 483
            y: 488
            width: 123
            height: 9
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle9
            x: 576
            y: 455
            width: 11
            height: 11
            color: "#ffffff"
        }
    }

}

