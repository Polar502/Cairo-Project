#include <gtk/gtk.h>
cairo_surface_t *bus;
cairo_surface_t *car;
cairo_surface_t *bridge_left;
cairo_surface_t *bridge_right;
cairo_surface_t *structure_bridge;




 
static void draw_function (GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {
   
   // Bus Section
   bus = cairo_image_surface_create_from_png("bus.png");
   cairo_set_source_surface(cr,bus,1,1);
   
   cairo_paint(cr);
   
   // Car Section
   car = cairo_image_surface_create_from_png("car.png");
   cairo_set_source_surface(cr,car,1,100);
   
   cairo_paint(cr);

   // Bridge Left Section
   bridge_left = cairo_image_surface_create_from_png("bridge-left.png");
   cairo_set_source_surface(cr,bridge_left,1,100);
   
   cairo_paint(cr);

   // Bridge Right Section
   bridge_right = cairo_image_surface_create_from_png("bridge-right.png");
   cairo_set_source_surface(cr,bridge_right,1,100);
   
   cairo_paint(cr);   
   
   // Structure Bridge Section
   structure_bridge = cairo_image_surface_create_from_png("structure-bridge.png");
   cairo_set_source_surface(cr,structure_bridge,1,100);
   
   cairo_paint(cr);

}
 
static void app_activate (GApplication *app, gpointer user_data) {
   GtkWidget *win = gtk_application_window_new (GTK_APPLICATION (app));
   GtkWidget *area = gtk_drawing_area_new ();
 
   gtk_window_set_title (GTK_WINDOW (win), "Dibujo");
   gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (area), draw_function, NULL, NULL);
   gtk_window_set_child (GTK_WINDOW (win), area);
 
   gtk_widget_show (win);
}
 
#define APPLICATION_ID "com.github.ToshioCP.da1"
 
int main (int argc, char **argv) {
   GtkApplication *app;
   int stat;
 
   app = gtk_application_new (APPLICATION_ID, G_APPLICATION_FLAGS_NONE);
   g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
   stat =g_application_run (G_APPLICATION (app), argc, argv);
   g_object_unref (app);

   // Destroy Section
   cairo_surface_destroy(bus);
   cairo_surface_destroy(car);
   cairo_surface_destroy(bridge_left);
   cairo_surface_destroy(bridge_right);
   cairo_surface_destroy(structure_bridge);

   return stat;
}
