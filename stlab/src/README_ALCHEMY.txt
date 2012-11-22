BUILD SWCS :

alc-on;
g++ -I. -O3 -swc alchemy_functionobjects.cpp -o functionobjects.swc;g++ -I. -O3 -swc alchemy_loop_unroll.cpp -o loop_unroll.swc;g++ -I. -O3 -swc alchemy_machine.cpp -o machine.swc;g++ -I. -O3 -swc alchemy_simple_types_constant_folding.cpp -o simple_types_constant_folding.swc;g++ -I. -O3 -swc alchemy_simple_types_loop_invariant.cpp -o simple_types_loop_invariant.swc;g++ -I. -O3 -swc alchemy_stepanov_abstraction.cpp -o stepanov_abstraction.swc;g++ -I. -O3 -swc alchemy_stepanov_vector.cpp -o stepanov_vector.swc;mv *.swc ../release;
alc-off;