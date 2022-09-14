#include <gtk/gtk.h>
cairo_surface_t *background;

cairo_surface_t *sun;
cairo_surface_t *cloud1;
cairo_surface_t *cloud2;
cairo_surface_t *airplane;
cairo_surface_t *cloud3;
cairo_surface_t *cloud4;
cairo_surface_t *cloud5;

cairo_surface_t *wheel;
cairo_surface_t *wheel_base;
cairo_surface_t *capa2;
cairo_surface_t *capa3;

cairo_surface_t *wave_1;
cairo_surface_t *wave_2;

cairo_surface_t *car_right;
cairo_surface_t *car_left;

cairo_surface_t *bus_right;
cairo_surface_t *bus_left;

cairo_surface_t *bridge_right;
cairo_surface_t *bridge_base_right;

cairo_surface_t *boat;

cairo_surface_t *bridge_left;
cairo_surface_t *bridge_base_left;

cairo_surface_t *wave_3;
cairo_surface_t *wave_4;

static void draw_function (GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {
   
   // ========== Background 1024 px - 575 px ==========
   background = cairo_image_surface_create_from_png("Background.png");
   cairo_set_source_surface(cr,background,0,0);
   cairo_paint(cr);   

   // ========== Sky (x, y) ==========
   sun = cairo_image_surface_create_from_png("Sun.png");
   cairo_set_source_surface(cr,sun,900,10);
   cairo_paint(cr);  

   cloud1 = cairo_image_surface_create_from_png("Cloud-1.png");
   cairo_set_source_surface(cr,cloud1,10,60);
   cairo_paint(cr);    

   cloud2 = cairo_image_surface_create_from_png("Cloud-2.png");
   cairo_set_source_surface(cr,cloud2,800,10);
   cairo_paint(cr);    

   airplane = cairo_image_surface_create_from_png("Airplane.png");
   cairo_set_source_surface(cr,airplane,350,50);
   cairo_paint(cr);     

   cloud3 = cairo_image_surface_create_from_png("Cloud-3.png");
   cairo_set_source_surface(cr,cloud3,280,70);
   cairo_paint(cr);    

   cloud4 = cairo_image_surface_create_from_png("Cloud-4.png");
   cairo_set_source_surface(cr,cloud4,450,40);
   cairo_paint(cr);       

   cloud5 = cairo_image_surface_create_from_png("Cloud-5.png");
   cairo_set_source_surface(cr,cloud5,670,80);
   cairo_paint(cr);     

   // ========== buildings background ==========
   wheel = cairo_image_surface_create_from_png("Wheel.png");
   cairo_set_source_surface(cr,wheel,40,150);
   cairo_paint(cr);     

   wheel_base = cairo_image_surface_create_from_png("Wheel-base.png");
   cairo_set_source_surface(cr,wheel_base,-25,250);
   cairo_paint(cr);    

   capa2 = cairo_image_surface_create_from_png("Capa-2.png");
   cairo_set_source_surface(cr,capa2,-25,100);
   cairo_paint(cr);  

   capa3 = cairo_image_surface_create_from_png("Capa-3.png");
   cairo_set_source_surface(cr,capa3,0,290);
   cairo_paint(cr);    

   // -------- Wave Back --------
   wave_1 = cairo_image_surface_create_from_png("Wave-1.png");
   cairo_set_source_surface(cr,wave_1,-25,515);
   cairo_paint(cr);   

   wave_2 = cairo_image_surface_create_from_png("Wave-2.png");
   cairo_set_source_surface(cr,wave_2,-25,530);
   cairo_paint(cr); 

   // -------- Cars Section --------
   car_left = cairo_image_surface_create_from_png("Car-left.png");
   cairo_set_source_surface(cr,car_left,150,435);
   cairo_paint(cr); 

   car_right = cairo_image_surface_create_from_png("Car-right.png");
   cairo_set_source_surface(cr,car_right,50,435);
   cairo_paint(cr);    

   bus_right = cairo_image_surface_create_from_png("Bus-right.png");
   cairo_set_source_surface(cr,bus_right,0,395);
   cairo_paint(cr);    

   bus_left = cairo_image_surface_create_from_png("Bus-left.png");
   cairo_set_source_surface(cr,bus_left,900,395);
   cairo_paint(cr);    

// ========== Buildings Bridge ==========

   bridge_left = cairo_image_surface_create_from_png("Bridge-left.png");
   cairo_set_source_surface(cr,bridge_left,360,400);
   cairo_paint(cr); 

   bridge_base_left = cairo_image_surface_create_from_png("Bridge-base-left.png");
   cairo_set_source_surface(cr,bridge_base_left,0,150);
   cairo_paint(cr); 

   // -------- Boat Section --------
   boat = cairo_image_surface_create_from_png("Boat-1.png");
   cairo_set_source_surface(cr,boat,600,400);
   cairo_paint(cr); 

   bridge_right = cairo_image_surface_create_from_png("Bridge-right.png");
   cairo_set_source_surface(cr,bridge_right,630,400);
   cairo_paint(cr); 

   bridge_base_right = cairo_image_surface_create_from_png("Bridge-base-right.png");
   cairo_set_source_surface(cr,bridge_base_right,400,150);
   cairo_paint(cr); 

   // -------- Wave front --------
   wave_3 = cairo_image_surface_create_from_png("Wave-3.png");
   cairo_set_source_surface(cr,wave_3,-25,545);
   cairo_paint(cr);   

   wave_4 = cairo_image_surface_create_from_png("Wave-4.png");
   cairo_set_source_surface(cr,wave_4,-25,560);
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
   cairo_surface_destroy(sun);
   cairo_surface_destroy(cloud1);
   cairo_surface_destroy(cloud2);
   cairo_surface_destroy(airplane);
   cairo_surface_destroy(cloud3);
   cairo_surface_destroy(cloud4);
   cairo_surface_destroy(cloud5);
   cairo_surface_destroy(wheel);
   cairo_surface_destroy(wheel_base);
   cairo_surface_destroy(capa2);
   cairo_surface_destroy(capa3);
   cairo_surface_destroy(wave_1);
   cairo_surface_destroy(wave_2);
   cairo_surface_destroy(car_right);
   cairo_surface_destroy(car_left);
   cairo_surface_destroy(bus_right);
   cairo_surface_destroy(bus_left);
   cairo_surface_destroy(bridge_left);
   cairo_surface_destroy(bridge_base_left);
   cairo_surface_destroy(boat);
   cairo_surface_destroy(bridge_right);
   cairo_surface_destroy(bridge_base_right);
   cairo_surface_destroy(wave_3);
   cairo_surface_destroy(wave_4);
   return stat;
}
