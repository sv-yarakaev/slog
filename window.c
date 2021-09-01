//
// Created by sv.yarakaev on 30.08.2021.
//

#include "window.h"

typedef struct {
    GtkWidget *window;
    GtkWidget *view;
    GtkWidget *statusbar;
    GtkTreeSelection *selection;
    GtkWidget *mainNotes;
} app_widgets;
