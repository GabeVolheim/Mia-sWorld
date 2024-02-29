#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "hangman.h"
#include "2048.h"

static void print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Hello World\n");
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Mias World");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_window_set_child (GTK_WINDOW (window), button);

  gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;
    char miaChoice;
    app = gtk_application_new ("com.area52.MiasWorld", 0);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
    return status;

    // for(;;)
    // {

    //     // Initial menu
    //     printf("Hello Mia\n");
    //     printf("What do you want to do today?\n");
    //     printf("1. Hangman\n2. 2048\n3. Quit\nYour Choice: ");
    //     scanf(" %c", &miaChoice);

    //     switch (miaChoice)
    //     {
            
    //     case '1':
    //         // Plays hangman
    //         playHangman();
    //         break;
    //     case '2':
    //         // Plays 2048
    //         play2048();
    //         break;
    //     case '3':
    //         // Mia quits
    //         puts("Okay bye loser :(");
    //         return 0;
    //         break;
    //     default:
    //         // Option is not availiable
    //         puts("\nThats not an option bruh\n");
    //         break;
    //     }
    // }
    // return 1;
}


