//
// EntityBody.cpp
// 2026-01-17
// qxoxrogue
//

#include "entity/EntityBody.h"

// take a body plan and remove an intermediate node



void EntityBody::prepend_to_seg_names(std::string s){
    for (unsigned int i = 0; i< segments.size(); i++){
        segments[i].name = s + segments[i].name ;
    }
}
void EntityBody::append_to_seg_names(std::string s){
    for (unsigned int i = 0; i< segments.size(); i++){
        segments[i].name = segments[i].name + s;
    }
}

EntityBody::EntityBody(const BodySegment & seg){
    segments.push_back(seg);
    segments[0].parent = -1;
}

EntityBody::EntityBody(){}


void EntityBody::contract(unsigned int X){
    if (X < segments.size()){
        int To = segments[X].parent;
        for (unsigned int i = 0; i< segments.size(); i++){
            if (segments[i].parent < 0) {continue;}
             else if ((unsigned int) segments[i].parent == X) {
                segments[i].parent = To;
            } else if ((unsigned int) segments[i].parent > X){
                segments[i].parent--;
            }
        }
        std::vector<BodySegment>::iterator it = segments.begin() + X;
        segments.erase(it);
    }
}
    
void EntityBody::attach_seg(unsigned int X, const BodySegment & seg){ // attach segment at X
    BodySegment teg = seg;
    teg.parent = X;
    segments.emplace_back(std::move(teg));
}

void EntityBody::attach_EB(unsigned int X, const EntityBody & EB){ // attach body part at X
    unsigned int l = segments.size();
    for (unsigned int i = 0; i < EB.segments.size(); i++){
        segments.emplace_back(EB.segments[i]);
        if (EB.segments[i].parent >= 0){
            segments[segments.size()].parent +=l;
        } else {
            segments[segments.size()].parent = X;
        }
    }
}
    
void EntityBody::repeat_seg_series(unsigned int X, unsigned int n, const BodySegment & seg){ // attach a chain of n copies of a segment at X
    for (unsigned int i = 1; i<=n; i++) {
        int newX = segments.size();
        attach_seg(X, seg);
        X = newX;
        segments[X].name += " " + std::to_string(i);
    }
} 
    
void EntityBody::repeat_EB_series(unsigned int X, unsigned int n, const EntityBody & EB){ // attach a chain of n copies of a body part at X
    // chain attaches to 0 of previous part of chain
    for (unsigned int i = 1; i<=n; i++){
        int newX = segments.size();
        EntityBody FB = EB;
        FB.append_to_seg_names(" " + std::to_string(i));
        attach_EB(X,FB); // this should really be implemented with && but I am not entirely sure of precisely what I can do with &&
        X = newX;
    }
}

void EntityBody::repeat_seg_star(unsigned int X, unsigned int n, const BodySegment & seg){ // attach n copies of a segment directly at X
    for (unsigned int i = 1; i<=n; i++) {
        int newX = segments.size();
        attach_seg(X, seg);
        segments[newX].name += " " + std::to_string(i);
    }
}

void EntityBody::repeat_EB_star(unsigned int X, unsigned int n, const EntityBody & EB){ // attach n copies of a body part directly at X
    for (unsigned int i = 1; i<=n; i++){
        EntityBody FB = EB;
        FB.append_to_seg_names(" " + std::to_string(i));
        attach_EB(X,FB); // this should really be implemented with && but I am not entirely sure of precisely what I can do with &&
    }
}

void EntityBody::LR_EB(unsigned int X, unsigned int n, const EntityBody & EB){ // attach n copies of a body part directly at X
    {
        EntityBody FB = EB;
        FB.prepend_to_seg_names("left ");
        attach_EB(X,FB); // this should really be implemented with && but I am not entirely sure of precisely what I can do with &&
    }
    {
        EntityBody FB = EB;
        FB.prepend_to_seg_names("right ");
        attach_EB(X,FB); // this should really be implemented with && but I am not entirely sure of precisely what I can do with &&
    }
}