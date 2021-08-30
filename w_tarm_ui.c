//
// Created by sv.yarakaev on 30.08.2021.
//

#include "w_tarm_ui.h"

GtkWidget *create_view_and_model(GtkWidget *view, app_widgets *widgets) {
    GtkTreeViewColumn *col;
    GtkCellRenderer *renderer;
    GtkTreeModel *model;

    col = gtk_tree_view_column_new();

    gtk_tree_view_column_set_title(col, "АРМ и ЦП");

    gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

    renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_column_pack_start(col, renderer, TRUE);
    gtk_tree_view_column_add_attribute(col, renderer,
                                       "text", COLUMN);

    model = create_and_fill_model();
    gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);
    g_object_unref(model);

    return view;
}

static GtkTreeModel *create_and_fill_model(void) {

    GtkTreeStore *treestore;
    GtkTreeIter toplevel, child;

    treestore = gtk_tree_store_new(NUM_COLS,
                                   G_TYPE_STRING);

    gtk_tree_store_append(treestore, &toplevel, NULL);
    gtk_tree_store_set(treestore, &toplevel,
                       COLUMN, "АРМы",
                       -1);

    gtk_tree_store_append(treestore, &child, &toplevel);
    gtk_tree_store_set(treestore, &child, COLUMN, "localhost", -1);
    gtk_tree_store_append(treestore, &child, &toplevel);
    gtk_tree_store_set(treestore, &child, COLUMN, "Основной", -1);
    gtk_tree_store_append(treestore, &child, &toplevel);
    gtk_tree_store_set(treestore, &child, COLUMN, "Резервный", -1);
    gtk_tree_store_append(treestore, &toplevel, NULL);
    gtk_tree_store_set(treestore, &toplevel, COLUMN, "ЦП", -1);

    gtk_tree_store_append(treestore, &child, &toplevel);
    gtk_tree_store_set(treestore, &child, COLUMN, "SPU1", -1);

    gtk_tree_store_append(treestore, &child, &toplevel);
    gtk_tree_store_set(treestore, &child, COLUMN, "SPU2", -1);

    gtk_tree_store_append(treestore, &child, &toplevel);
    gtk_tree_store_set(treestore, &child, COLUMN, "ZIP", -1);

    return GTK_TREE_MODEL(treestore);
}


void on_changed(GtkWidget *widget, gpointer statusbar) {

    GtkTreeIter iter;
    GtkTreeModel *model;
    gchar *value;

    g_print("on changed loaded.\n");
    if (gtk_tree_selection_get_selected(
            GTK_TREE_SELECTION(widget), &model, &iter)) {

        gtk_tree_model_get(model, &iter, COLUMN, &value,  -1);
        gtk_statusbar_push(GTK_STATUSBAR(statusbar),
                           gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar),
                                                        value), value);
        gtk_window_set_title(GTK_WINDOW(widgets->window), value);
        g_free(value);
    }
}