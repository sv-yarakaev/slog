//
// Created by sv.yarakaev on 30.08.2021.
//

#ifndef SLOG_WINDOW_H
#define SLOG_WINDOW_H
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *view;
    GtkWidget *statusbar;
    GtkTreeSelection *selection;
    GtkWidget *mainNotes;
} app_widgets;


//app_widgets *widgets = g_slice_new(app_widgets);
#endif//SLOG_WINDOW_H
