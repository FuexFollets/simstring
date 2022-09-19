#pragma once 

#include <bits/stdc++.h>

namespace sim {
    struct simstring {
        /*
         * Stored values
        */

        char* string_val;
        std::size_t length;
        
        struct iterator {
            iterator& operator++();
            iterator& operator--();

            char& operator*();

            template <typename T_int> iterator operator+(T_int);
            template <typename T_int> iterator operator-(T_int);

            bool&& operator==(iterator);
            bool&& operator!=(iterator);
        };


        struct split_ref_iterator : public iterator { simstring& operator*(); };
        struct split_iterator : public iterator { simstring&& operator*(); };
        struct find_iterator : public iterator { std::size_t&& operator*(); };
        struct slice_iterator : public iterator { simstring&& operator*(); };
        struct slice_ref_iterator : public iterator { simstring& operator*(); };

        simstring() {}
        simstring(const char*);
        simstring(const std::string&);
        simstring(const std::string&&);
        simstring(const char&); 
        simstring(const char&&);

        simstring(const simstring&);
        simstring(const simstring&&);

        ~simstring();

        template <typename T_string> void operator=(T_string);
        template <typename T_int> char& operator[](T_int);
        template <typename T_app> simstring operator+(T_app);
        template <typename T_app> simstring& operator+=(T_app);
        template <typename T_string> bool operator==(T_string);
        template <typename T_string> bool operator!=(T_string);

        template <typename T_split> iterator split(T_split);
        template <typename T_split> iterator split_include(T_split);
        template <typename T_split> iterator split_ref(T_split);
        template <typename T_split> iterator split_ref_include(T_split);
        template <typename T_find> std::size_t find(T_find);
        template <typename T_find> find_iterator find_all(T_find);
        template <typename T_start, typename T_end> simstring&& sub_string(T_start, T_end);
        template <typename T_start, typename T_end> simstring& sub_string_ref(T_start, T_end);
        template <typename T_first, typename T_second> simstring& swap(T_first, T_second);
        template <typename T_int1, typename T_int2, typename T_int3> slice_iterator slice(T_int1, T_int2, T_int3);
        template <typename T_int1, typename T_int2, typename T_int3> slice_iterator slice_ref(T_int1, T_int2, T_int3);
            

        iterator begin();
        iterator end();

        std::size_t size() const;
        std::size_t len() const;

        simstring& del_string_data();

        friend std::ostream& operator<<(std::ostream&, simstring&);
        friend std::ostream& operator<<(std::ostream&, simstring&&);

        operator char* ();
        operator const char* ();
        operator std::string ();
    };
}