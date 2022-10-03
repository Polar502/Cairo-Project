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

gint x_cloud1;
gint x_cloud2;
gint x_cloud3;
gint x_cloud4;
gint x_cloud5;

gint x_car_right;
gint x_car_left;
gint x_airplane;
gint x_boat;
gint x_bus_right;
gint x_bus_left;

gint x_wave_1;
gint x_wave_2;
gint x_wave_3;
gint x_wave_4;


static void draw_function (GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {
   
   // ========== Background 1024 px - 575 px ==========
   background = cairo_image_surface_create_from_png("Background.png");
   cairo_set_source_surface(cr,background,0,0);
   cairo_paint(cr);   

   // ========== Sky (x, y) ==========
   sun = cairo_image_surface_create_from_png("Sun.png");
   cairo_set_source_surface(cr,sun,900,5);
   cairo_paint(cr);  

   if(x_cloud1<1050){
      x_cloud1 += 1;
   } else {
      x_cloud1 = -200;
   }
   cloud1 = cairo_image_surface_create_from_png("Cloud-1.png");
   cairo_set_source_surface(cr,cloud1,0+x_cloud1,90);
   cairo_paint(cr);    

   if(x_cloud2<1050){
      x_cloud2 += 1;
   } else {
      x_cloud2 = -200;
   }   
   cloud2 = cairo_image_surface_create_from_png("Cloud-2.png");
   cairo_set_source_surface(cr,cloud2,0+x_cloud2,10);
   cairo_paint(cr);      

   if(x_cloud3<1050){
      x_cloud3 += 1;
   } else {
      x_cloud3 = -200;
   }   
   cloud3 = cairo_image_surface_create_from_png("Cloud-3.png");
   cairo_set_source_surface(cr,cloud3,0+x_cloud3,20);
   cairo_paint(cr); 

   if(x_airplane > -100){
      x_airplane -= 2;
   } else {
      x_airplane = 1030;
   }
   airplane = cairo_image_surface_create_from_png("Airplane.png");
   cairo_set_source_surface(cr,airplane,0+x_airplane,55);
   cairo_paint(cr);      

   if(x_cloud4<1050){
      x_cloud4 += 1;
   } else {
      x_cloud4 = -200;
   }   
   cloud4 = cairo_image_surface_create_from_png("Cloud-4.png");
   cairo_set_source_surface(cr,cloud4,0+x_cloud4,75);
   cairo_paint(cr);       

   if(x_cloud5<1050){
      x_cloud5 += 1;
   } else {
      x_cloud5 = -200;
   }
   cloud5 = cairo_image_surface_create_from_png("Cloud-5.png");
   cairo_set_source_surface(cr,cloud5,0+x_cloud5,65);
   cairo_paint(cr);     

   // ========== buildings background ==========
   wheel = cairo_image_surface_create_from_png("Wheel.png");
   cairo_set_source_surface(cr,wheel,41,123);
   cairo_paint(cr);     

   wheel_base = cairo_image_surface_create_from_png("Wheel-base.png");
   cairo_set_source_surface(cr,wheel_base,-25,220);
   cairo_paint(cr);    

   capa2 = cairo_image_surface_create_from_png("Capa-2.png");
   cairo_set_source_surface(cr,capa2,-25,60);
   cairo_paint(cr);  

   capa3 = cairo_image_surface_create_from_png("Capa-3.png");
   cairo_set_source_surface(cr,capa3,-25,245);
   cairo_paint(cr);    

   if(x_wave_1 < 300){
      x_wave_1 += 1;
   } else {
      x_wave_1 = -500;
   }  
   wave_1 = cairo_image_surface_create_from_png("Wave-1.png");
   cairo_set_source_surface(cr,wave_1,-500+x_wave_1,500);
   cairo_paint(cr);   

   if(x_wave_2 < 300){
      x_wave_2 += 1;
   } else {
      x_wave_2 = -500;
   }  
   wave_2 = cairo_image_surface_create_from_png("Wave-2.png");
   cairo_set_source_surface(cr,wave_2,-500+x_wave_2,520);
   cairo_paint(cr); 

   // -------- Cars Section --------
   if(x_car_left > -100){
      x_car_left -= 10;
   } else {
      x_car_left = 1100;
   }  
   car_left = cairo_image_surface_create_from_png("Car-left.png");
   cairo_set_source_surface(cr,car_left,0+x_car_left,435);
   cairo_paint(cr); 

   if(x_bus_left > -100){
      x_bus_left -= 10;
   } else {
      x_bus_left = 1300;
   }  
   bus_left = cairo_image_surface_create_from_png("Bus-left.png");
   cairo_set_source_surface(cr,bus_left,0+x_bus_left,395);
   cairo_paint(cr);    

   if(x_car_right < 1100){
      x_car_right += 10;
   } else {
      x_car_right = -300;
   }  
   car_right = cairo_image_surface_create_from_png("Car-right.png");
   cairo_set_source_surface(cr,car_right,0+x_car_right,435);
   cairo_paint(cr);    

   if(x_bus_right < 1100){
      x_bus_right += 10;
   } else {
      x_bus_right = -300;
   }  
   bus_right = cairo_image_surface_create_from_png("Bus-right.png");
   cairo_set_source_surface(cr,bus_right,0+x_bus_right,395);
   cairo_paint(cr);    


// ========== Buildings Bridge ==========

   bridge_left = cairo_image_surface_create_from_png("Bridge-left.png");
   cairo_set_source_surface(cr,bridge_left,360,400);
   cairo_paint(cr); 

   bridge_base_left = cairo_image_surface_create_from_png("Bridge-base-left.png");
   cairo_set_source_surface(cr,bridge_base_left,0,150);
   cairo_paint(cr); 

   // -------- Boat Section --------
   x_boat -= 4;
   boat = cairo_image_surface_create_from_png("Boat-1.png");
   cairo_set_source_surface(cr,boat,600+x_boat,400);
   cairo_paint(cr); 

   bridge_right = cairo_image_surface_create_from_png("Bridge-right.png");
   cairo_set_source_surface(cr,bridge_right,630,400);
   cairo_paint(cr); 

   bridge_base_right = cairo_image_surface_create_from_png("Bridge-base-right.png");
   cairo_set_source_surface(cr,bridge_base_right,400,150);
   cairo_paint(cr); 

   // -------- Wave front --------
   if(x_wave_3 < 300){
      x_wave_3 += 1;
   } else {
      x_wave_3 = -500;
   }  
   wave_3 = cairo_image_surface_create_from_png("Wave-3.png");
   cairo_set_source_surface(cr,wave_3,-500+x_wave_3,540);
   cairo_paint(cr);   

   if(x_wave_4 < 300){
      x_wave_4 += 1;
   } else {
      x_wave_4 = -520;
   }  
   wave_4 = cairo_image_surface_create_from_png("Wave-4.png");
   cairo_set_source_surface(cr,wave_4,-520+x_wave_4,560);
   cairo_paint(cr);   

}

gboolean time_handler(GtkWidget* widget) {
	gtk_widget_queue_draw(widget);

	return TRUE;
}

 
static void app_activate (GApplication *app, gpointer user_data) {
	GtkWidget *ventana = gtk_application_window_new (GTK_APPLICATION (app));
	GtkWidget *dibujo = gtk_drawing_area_new ();
	
	gtk_window_set_title (GTK_WINDOW (ventana), "Dibujo");
	gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (dibujo), draw_function, NULL, NULL);
	gtk_window_set_child (GTK_WINDOW (ventana), dibujo);
   gtk_window_set_default_size(GTK_WINDOW (ventana),1025,600);
   	
	gtk_widget_set_hexpand(dibujo,true);
	gtk_widget_set_vexpand(dibujo,true);
	
	g_timeout_add(100, (GSourceFunc) time_handler, (gpointer) dibujo);
	gtk_widget_show(ventana);
 
}
static void app_open (GApplication *app, GFile **files, gint n_files, gchar *hint, gpointer user_data) {
	app_activate(app,user_data);
}
 
#define APPLICATION_ID "info.lfac.puente"
 
int main (int argc, char **argv) {
   GtkApplication *app;
   int stat;

   x_cloud1 = -40;
   x_cloud2 = 950;
   x_airplane = 1030;
   x_cloud3 = 250;
   x_cloud4 = 450;
   x_cloud5 = 770;


   x_car_right = -800;
   x_bus_right = -200;
   x_car_left = 1100;
   x_bus_left = 1400;
   x_boat = 1100;
   x_wave_1 = 0;
   x_wave_2 = 0;
   x_wave_3 = 0;
   x_wave_4 = 0;

 
	app = gtk_application_new (APPLICATION_ID, G_APPLICATION_HANDLES_OPEN);
	g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
	g_signal_connect (app, "open", G_CALLBACK (app_open), NULL);
	stat = g_application_run (G_APPLICATION (app), argc, argv);
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
