Line 13: Char 17: error: no viable overloaded '='
            it1 = find(v.begin(), v.end(), tolower(p));
            ~~~ ^ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_iterator.h:784:11: note: candidate function (the implicit copy assignment operator) not viable: no known conversion from '__normal_iterator<char *, vector<char, allocator<char>>>' to 'const __normal_iterator<int *, vector<int, allocator<int>>>' for 1st argument
    class __normal_iterator
          ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_iterator.h:784:11: note: candidate function (the implicit move assignment operator) not viable: no known conversion from '__normal_iterator<char *, vector<char, allocator<char>>>' to '__normal_iterator<int *, vector<int, allocator<int>>>' for 1st argument