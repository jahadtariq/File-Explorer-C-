#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "folder.h"
#include <string>
#include "dialogs.h"
#include "algorithm.h"
#include <stdlib.h>
#include <cstdio>
#include <fstream>

class Main_window : public Gtk::Window
{
    public:
        Main_window(bool initialize_bookmarks);
        virtual ~Main_window();

    protected:
        void rename_data();
        void paste_click();
        void duplicate_data();
        void create_new_file_click();

        void delete_bookmarks();
        void add_to_bookmarks();
        void update_bookmarks_bar();
        void create_new_folder_click();
        
        void on_grid_button_click(std::string name_of_clicked_object);
        void populate_grid(std::string name, std::string pathname);
        void empty_grid();
        
        void on_icons_click(GdkEventButton* event);
        bool on_quitclick(GdkEventAny* event);

        void update_path(); 
        void update_to_a_path();  
        void update_status_bar(std::string msg); 
        void back_button();
        
        bool is_a_file(std::string path_name);
        bool is_a_folder(std::string filename);
        int icons_type(std::string name);
        
        void open_terminal_click();    
        void properties_click();    
        void delete_data();    
        void search();
        void save();

        void about_dialog();

    private:
        bool edit_mode;         
        bool copy_over_cut;     

        std::string copy_from;   
        std::string copy_name;  
        std::string selected_data;
        std::string selected_bookmark_data;
        
        std::vector <Gtk::Button*> buttons;
        std::vector <Gtk::ToolButton*> bookmarks_buttons; 
        std::vector <std::string> path_stack;   
        std::vector <std::string> bookmarks_path; 
        
        Folder *folder_path; 
        
        
        Gtk::Toolbar *bookmarkbar; 
        Gtk::Label *status_bar;
        Gtk::ToggleToolButton *table_view;
        Gtk::ScrolledWindow *scrolledwindow;
        Gtk::Entry *label;         
        Gtk::Grid *grid_button;    
        Gtk::Entry *search_entry;  
        Gtk::Grid *grid;           

};

#endif
