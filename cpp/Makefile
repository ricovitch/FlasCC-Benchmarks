CC=/cygdrive/d/Tools/flascc/1.0.0/sdk/usr/bin/gcc
CXX=/cygdrive/d/Tools/flascc/1.0.0/sdk/usr/bin/g++
CCFLAGS=-emit-swf
INCLUDE=-I.

all: swf swf_O4

swf:
	$(CXX) $(CCFLAGS) $(INCLUDE) getmax.c -o bin/getmax.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_template_1.cpp -o bin/class_template_1.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) getmax_template.cpp -o bin/getmax_template.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) template_specialization.cpp -o bin/template_specialization.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_overloading_operators.cpp -o bin/class_overloading_operators.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_static_members.cpp -o bin/class_static_members.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_friend_functions.cpp -o bin/class_friend_functions.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_friend.cpp -o bin/class_friend.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_derived.cpp -o bin/class_derived.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_multiple_inheritance.cpp -o bin/class_multiple_inheritance.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_polymorphism_1.cpp -o bin/class_polymorphism_1.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_virtual_members.cpp -o bin/class_virtual_members.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) class_virtual_functions.cpp -o bin/class_virtual_functions.swf
	$(CXX) $(CCFLAGS) $(INCLUDE) namespaces.cpp -o bin/namespaces.swf
	
swf_O4:
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) getmax.c -o bin/getmax.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_template_1.cpp -o bin/class_template_1_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) getmax_template.cpp -o bin/getmax_template_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) template_specialization.cpp -o bin/template_specialization_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_overloading_operators.cpp -o bin/class_overloading_operators_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_static_members.cpp -o bin/class_static_members_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_friend_functions.cpp -o bin/class_friend_functions_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_friend.cpp -o bin/class_friend_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_derived.cpp -o bin/class_derived_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_multiple_inheritance.cpp -o bin/class_multiple_inheritance_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_polymorphism_1.cpp -o bin/class_polymorphism_1_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_virtual_members.cpp -o bin/class_virtual_members_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) class_virtual_functions.cpp -o bin/class_virtual_functions_O4.swf
	$(CXX) $(CCFLAGS) -O4 $(INCLUDE) namespaces.cpp -o bin/namespaces_O4.swf