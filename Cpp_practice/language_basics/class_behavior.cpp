int x;                         // global variable
void f()                       // function definition
{
      static int y;            // static variable y can be used by
                               // local class
      int x;                   // auto variable x cannot be used by
                               // local class
      extern int g();          // extern function g can be used by
                               // local class

      class local              // local class
      {
            int g() { return x; }      // error, local variable x
                                       // cannot be used by g
            int h() { return y; }      // valid,static variable y
            int k() { return ::x; }    // valid, global x
            int l() { return g(); }    // valid, extern function g
      };
}

int main()
{
      local* z;                // error: the class local is not visible
      // ...}
}