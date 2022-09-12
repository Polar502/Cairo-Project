#include <gtk/gtk.h>
cairo_surface_t *background;
cairo_surface_t *clouds;
cairo_surface_t *capa1;
cairo_surface_t *capa2;
cairo_surface_t *capa3;
cairo_surface_t *cars;
cairo_surface_t *boats;
cairo_surface_t *bridge;


 
static void draw_function (GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {
   
   // background Section
   background = cairo_image_surface_create_from_png("Background.png");
   cairo_set_source_surface(cr,background,0,0);

   cairo_paint(cr);   


   // Clouds Section
   clouds = cairo_image_surface_create_from_png("Clouds.png");
   cairo_set_source_surface(cr,clouds,0,0);   
   
   cairo_paint(cr);   

   // Capa3 Section
   capa3 = cairo_image_surface_create_from_png("Capa3.png");
   cairo_set_source_surface(cr,capa3,0,100);
   
   cairo_paint(cr);    

   // Capa2 Section
   capa2 = cairo_image_surface_create_from_png("Capa2.png");
   cairo_set_source_surface(cr,capa2,0,30);
   
   cairo_paint(cr); 

   // Capa1 Section
   capa1 = cairo_image_surface_create_from_png("Capa1.png");
   cairo_set_source_surface(cr,capa1,0,270);
   
   cairo_paint(cr);    

   // Cars Section
   cars = cairo_image_surface_create_from_png("Cars.png");
   cairo_set_source_surface(cr,cars,20,440);
   
   cairo_paint(cr);  
   
   // Boats Section
   boats = cairo_image_surface_create_from_png("Boat.png");
   cairo_set_source_surface(cr,boats,710,450);
   
   cairo_paint(cr);  
   


   // Bridge Section
   bridge = cairo_image_surface_create_from_png("Bridge.png");
   cairo_set_source_surface(cr,bridge,0,100);
   
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
   cairo_surface_destroy(background);
   cairo_surface_destroy(clouds);
   cairo_surface_destroy(capa1);
   cairo_surface_destroy(capa2);
   cairo_surface_destroy(capa3);
   cairo_surface_destroy(cars);
   cairo_surface_destroy(boats);
   
   cairo_surface_destroy(bridge);

   return stat;
}
