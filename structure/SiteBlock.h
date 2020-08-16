#pragma once
#include <filesystem>

/*
  A SiteBlock is any part of the site that can be referenced by a path and has things posted in it.
  A Blog is a SiteBlock and has blog posts posted in it.  A Forum is a SiteBlock and has posts in it.
  A single site can have many SiteBlocks of the same sort, in whatever hierarchy is desirable.
*/

class SiteBlock {
    std::filesystem::path my_path;  // Base directory of where my stuff will be stored
    unsigned int my_id;             // My identifying number in the journal and elsewhere
    std::string my_name;            // My human friendly name
};


