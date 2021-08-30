#include <gtk/gtk.h>
#include "w_tarm_ui.h"


#define MAIN_UI "main.ui"
#define TREE_ARMS "treeMachines"
#define STATUSBAR "mainStatusBar"
#define SELECT_TREE "selectTreeMachines"


typedef struct {
    GtkWidget *window;
    GtkWidget *view;
    GtkWidget *statusbar;
    GtkTreeSelection *selection;
    GtkWidget *mainNotes;
} app_widgets;



int main(int argc, char **argv) {

    GtkBuilder *builder;
    GtkWidget *window;

    app_widgets *widgets = g_slice_new(app_widgets);
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file(MAIN_UI);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));

    widgets->view =  GTK_WIDGET(gtk_builder_get_object(builder, TREE_ARMS));
    widgets->view = create_view_and_model(widgets->view);

    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);
    gtk_widget_show_all(window);

    gtk_main();
    g_slice_free(app_widgets, widgets);


    return 0;
}


//signals
void on_window_main_destroy() {
    g_print("Correct exit.\n");
    gtk_main_quit();
}