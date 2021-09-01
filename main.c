#include <gtk/gtk.h>
#include "w_tarm_ui.h"
#include "window.h"
#include "signal_note.h"

#define MAIN_UI "main.xml"
#define TREE_ARMS "treeMachines"
#define STATUSBAR "mainStatusBar"
#define SELECT_TREE "selectTreeMachines"





int main(int argc, char **argv) {

    GtkBuilder *builder;
    GtkWidget *window;

    app_widgets *widgets = g_slice_new(app_widgets);
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file(MAIN_UI);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));

    widgets->view =  GTK_WIDGET(gtk_builder_get_object(builder, TREE_ARMS));
    widgets->view = create_view_and_model(widgets->view, widgets);

    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);
    //gtk_window_fullscreen(window);
    gtk_widget_show_all(window);

    gtk_window_fullscreen(GTK_WINDOW(window));

    gtk_main();
    g_slice_free(app_widgets, widgets);


    return 0;
}


//signals
void on_window_main_destroy() {
    g_print("Correct exit.\n");
    gtk_main_quit();
}

void on_mainWindow_window_state_event(GtkWidget* self, GdkEventWindowState event, gpointer ues)  {
    gtk_window_fullscreen(GTK_WINDOW(self));
}