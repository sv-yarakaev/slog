//
// Created by sv.yarakaev on 30.08.2021.
//

#include "signal_note.h"

 void on_changed_note(GtkWidget *widget, gpointer note) {
    g_print("Note change\n");
    GtkWidget *tab2_label;
    tab2_label = gtk_label_new ("first page");
}