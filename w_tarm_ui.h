//
// Created by sv.yarakaev on 30.08.2021.
//

#ifndef SLOG_W_TARM_UI_H
#define SLOG_W_TARM_UI_H
#include <gtk/gtk.h>
#include "window.h"

enum {
    COLUMN = 0,
    NUM_COLS
};

void fill_view(GtkWidget *);
GtkWidget *create_view_and_model(GtkWidget *view, app_widgets *widgets);
static GtkTreeModel *create_and_fill_model(void);
void on_changed(GtkWidget *widget, gpointer statusbar);
#endif//SLOG_W_TARM_UI_H
