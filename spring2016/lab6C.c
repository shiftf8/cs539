// Lab6c new start

#include "roommate.h"

int main(){
    struct RoommateInfo* x;
    
    x = set_student_name(new_student(), "Rob Lamog");
    print_roommate_info(x);
    
    return 0;
}