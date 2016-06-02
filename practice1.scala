val greetStrings = new Array[String](3)
greetStrings(0) = "Hello"
greetStrings(1) = ", "
greetStrings(2) = "world!\n"
for(arg<-greetStrings){for(arg2<-arg)println(arg2)}
