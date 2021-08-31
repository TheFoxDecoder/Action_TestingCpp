all:
      g++ -std=c++17 main.cpp -o hello
      g++ -std=c++17 helloTest.cpp -lcppunit -o helloTest

test:
      chmod +x hello
      ./helloTest

clean:
      $(RM) hello helloTest