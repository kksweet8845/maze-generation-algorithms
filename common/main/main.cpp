/**
 * @file    main.cpp
 * @author  Ferenc Nemeth
 * @date    18 Nov 2018
 * @brief   Generates a maze with a selected width, height and algorithm, then saves it.
 *
 *          Copyright (c) 2018 Ferenc Nemeth - https://github.com/ferenc-nemeth/
 */ 



#include "aldous_broder.h"
#include "binary_tree.h"
#include "kruskal.h"
#include "prim.h"
#include "recursive_backtracking.h"
#include "recursive_division.h"

#include "solver.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include "file_system.h"


#define WALL 0
#define PATH 1
#define TRAP 2
#define HOST 3

std::vector<int32_t> ans(std::vector<int32_t> vect);
std::vector<std::vector<uint32_t>> output_maze_corner(std::vector<std::vector<uint32_t>> vect, std::string filename, int32_t hostages, int32_t traps);


std::vector<std::vector<uint32_t>> add_somethingfun(std::vector<std::vector<uint32_t>> vect);
std::vector<std::vector<uint32_t>> output_maze(std::vector<std::vector<uint32_t>> vect, std::string filename);
/**
 * @brief   Main function.
 * @param   void
 * @return  0
 */
int32_t main(void)
{
  uint32_t width        = 0u;
  uint32_t height       = 0u;
  uint32_t algorithm    = 0u;
  int32_t  maze_num     = 1;
  std::string filename  = "output/";
  std::string rawfilename = "rawoutput/";
  time_t current_time   = 0u;
  maze::file_system m_file_system;
  maze::solver m_solver;
  std::vector<std::vector<uint32_t>> maze;
  std::vector<std::vector<uint32_t>> new_maze;
  
  std::cout << "\n--------------------------------\n";
  std::cout << "   Maze generation algorithms\n";
  std::cout << "https://github.com/ferenc-nemeth\n";
  std::cout << "--------------------------------\n\n";
  std::cout << "Width of the maze (must be odd number): ";
  std::cin  >> width;
  std::cout << "Height of the maze (must be odd number): ";
  std::cin  >> height;
  std::cout << "\n";
  std::cout << "Aldous-Broder ------------ 1\n";
  std::cout << "Binary tree -------------- 2\n";
  std::cout << "Kruskal's ---------------- 3\n";
  std::cout << "Prim's ------------------- 4\n";
  std::cout << "Recursive backtracking --- 5\n";
  std::cout << "Recursive division ------- 6\n";
  std::cout << "Select an algorithm: ";
  std::cin  >> algorithm;
  std::cout << "Output the nubmer of maze:\n";
  std::cin  >> maze_num;

  if(maze_num <= 0) maze_num = 1;

  /* Save the image with the current Unix-time, */
  /* so it is possible to run the software multiple times without overwriting the outputs. */
  time(&current_time);
  filename += std::to_string(current_time);
  rawfilename += std::to_string(current_time);

  /* Generate the empty area, put entrance and exit on it, then generate the actual maze. */
  if (1u == algorithm)
  {
    int i=0;
    rawfilename += "_Aldout_Broder.txt";
    std::fstream file;
    while(maze_num--) {
      filename  = "output/";
      // rawfilename = "rawoutput/";
      
                                 /**< Get the maze. */
      for(int host=0;host<=4;host++) {
        for(int traps=0;traps<=8;traps+=2) {
          maze::aldous_broder m_maze(height, width);            /**< Initialize. */
          m_maze.set_cell(0u,1u, m_maze.hole);                  /**< Entrance point at top-left. */
          m_maze.set_cell(height-1u, width-2u, m_maze.hole);    /**< Exit point at bottom-right. */
          m_maze.generate();                                    /**< The actual generation. */
          maze = m_maze.get_maze();  
          new_maze = output_maze_corner(maze, rawfilename, host, traps);
          i++;
        }
      }                /**< Save. */
      // m_solver.dijkstra(maze, 0u, 1u, height-1u, width-2u); /**< Solve it. */
      // filename.insert(filename.size()-4u, "_Solved");       /**< Rename the filename. */
    }
    std::cout << i << std::endl;
  }
  else if (2u == algorithm)
  {
    // maze::binary_tree m_maze(height, width);
    // m_maze.set_cell(0u,1u, m_maze.hole);
    // m_maze.set_cell(height-1u, width-2u, m_maze.hole);
    // m_maze.generate();
    // filename += "_Binary_tree.png";
    // maze = m_maze.get_maze();
    // m_file_system.save(maze, filename);
    // m_solver.dijkstra(maze, 0u, 1u, height-1u, width-2u);
    // filename.insert(filename.size()-4u, "_Solved");
    // m_file_system.save(maze, filename);
    int i=0;
    rawfilename += "_Binary_tree.txt";
    std::fstream file;
    while(maze_num--) {
      filename  = "output/";
      
      
      for(int host=0;host<=4;host++) {
        for(int traps=0;traps<=8;traps+=2) {
          maze::binary_tree m_maze(height, width);            /**< Initialize. */
          m_maze.set_cell(0u,1u, m_maze.hole);                  /**< Entrance point at top-left. */
          m_maze.set_cell(height-1u, width-2u, m_maze.hole);    /**< Exit point at bottom-right. */
          m_maze.generate();                                    /**< The actual generation. */
          maze = m_maze.get_maze();                             /**< Get the maze. */
          new_maze = output_maze_corner(maze, rawfilename, host, traps);
          i++;
        }
      }
    }
    std::cout << i << std::endl;

  }
  else if (3u == algorithm)
  {
    // maze::kruskal m_maze(height, width);
    // m_maze.set_cell(0u,1u, m_maze.hole);
    // m_maze.set_cell(height-1u, width-2u, m_maze.hole);
    // m_maze.generate();
    // filename += "_Kruskal.png";
    // maze = m_maze.get_maze();
    // m_file_system.save(maze, filename);
    // m_solver.dijkstra(maze, 0u, 1u, height-1u, width-2u);
    // filename.insert(filename.size()-4u, "_Solved");
    // m_file_system.save(maze, filename);

    int i=0;
    rawfilename += "_Kruskal.txt";
    std::fstream file;
    while(maze_num--) {
      filename  = "output/";
      
      
      for(int host=0;host<=4;host++) {
        for(int traps=0;traps<=8;traps+=2) {
          maze::kruskal m_maze(height, width);            /**< Initialize. */
          m_maze.set_cell(0u,1u, m_maze.hole);                  /**< Entrance point at top-left. */
          m_maze.set_cell(height-1u, width-2u, m_maze.hole);    /**< Exit point at bottom-right. */
          m_maze.generate();                                    /**< The actual generation. */
          maze = m_maze.get_maze();                             /**< Get the maze. */
          new_maze = output_maze_corner(maze, rawfilename, host, traps);
          i++;
        }
      }
    }
    std::cout << i << std::endl;

  }
  else if (4u == algorithm)
  {
    // maze::prim m_maze(height, width);
    // m_maze.set_cell(0u,1u, m_maze.hole);
    // m_maze.set_cell(height-1u, width-2u, m_maze.hole);
    // m_maze.generate();
    // filename += "_Prim.png";
    // maze = m_maze.get_maze();
    // m_file_system.save(maze, filename);
    // m_solver.dijkstra(maze, 0u, 1u, height-1u, width-2u);
    // filename.insert(filename.size()-4u, "_Solved");
    // m_file_system.save(maze, filename);

    int i=0;
    rawfilename += "_Prim.txt";
    std::fstream file;
    while(maze_num--) {
      filename  = "output/";
      
      for(int host=0;host<=4;host++) {
        for(int traps=0;traps<=8;traps+=2) {
          maze::prim m_maze(height, width);            /**< Initialize. */
          m_maze.set_cell(0u,1u, m_maze.hole);                  /**< Entrance point at top-left. */
          m_maze.set_cell(height-1u, width-2u, m_maze.hole);    /**< Exit point at bottom-right. */
          m_maze.generate();                                    /**< The actual generation. */
          maze = m_maze.get_maze();                             /**< Get the maze. */
          new_maze = output_maze_corner(maze, rawfilename, host, traps);
          i++;
        }
      }
    }
    std::cout << i << std::endl;

  }
  else if (5u == algorithm)
  {
    // maze::recursive_backtracking m_maze(height, width);
    // m_maze.set_cell(0u,1u, m_maze.hole);
    // m_maze.set_cell(height-1u, width-2u, m_maze.hole);
    // m_maze.generate();
    // filename += "_Recursive_backtracking.png";
    // maze = m_maze.get_maze();
    // m_file_system.save(maze, filename);
    // m_solver.dijkstra(maze, 0u, 1u, height-1u, width-2u);
    // filename.insert(filename.size()-4u, "_Solved");
    // m_file_system.save(maze, filename);

    int i=0;
    rawfilename += "_Recursive_backtracking.txt";
    std::fstream file;
    while(maze_num--) {
      filename  = "output/";
      
      for(int host=0;host<=4;host++) {
        for(int traps=0;traps<=8;traps+=2) {
          maze::recursive_backtracking m_maze(height, width);            /**< Initialize. */
          m_maze.set_cell(0u,1u, m_maze.hole);                  /**< Entrance point at top-left. */
          m_maze.set_cell(height-1u, width-2u, m_maze.hole);    /**< Exit point at bottom-right. */
          m_maze.generate();                                    /**< The actual generation. */
          maze = m_maze.get_maze();                             /**< Get the maze. */
          new_maze = output_maze_corner(maze, rawfilename, host, traps);
          i++;
        }
      }
    }
    std::cout << i << std::endl;


  }
  else if (6u == algorithm)
  {
    // maze::recursive_division m_maze(height, width);
    // m_maze.set_cell(0u,1u, m_maze.hole);
    // m_maze.set_cell(height-1u, width-2u, m_maze.hole);
    // m_maze.generate();
    // filename += "_Recursive_division.png";
    // maze = m_maze.get_maze();
    // m_file_system.save(maze, filename);
    // m_solver.dijkstra(maze, 0u, 1u, height-1u, width-2u);
    // filename.insert(filename.size()-4u, "_Solved");
    // m_file_system.save(maze, filename);

    int i=0;
    rawfilename += "_Recursive_division.txt";
    std::fstream file;
    while(maze_num--) {
      filename  = "output/";
      
      for(int host=0;host<=4;host++) {
        for(int traps=0;traps<=8;traps+=2) {
          maze::recursive_division m_maze(height, width);            /**< Initialize. */
          m_maze.set_cell(0u,1u, m_maze.hole);                  /**< Entrance point at top-left. */
          m_maze.set_cell(height-1u, width-2u, m_maze.hole);    /**< Exit point at bottom-right. */
          m_maze.generate();                                    /**< The actual generation. */
          maze = m_maze.get_maze();                             /**< Get the maze. */
          new_maze = output_maze_corner(maze, rawfilename, host, traps);
          i++;
        }
      }
    }
    std::cout << i << std::endl;

  }
  else
  {
    throw std::invalid_argument("Wrong algorithm number!");
  }

  std::cout << "\nMaze generated and saved!\n\n";

  return 0;
}


uint32_t wall_around(std::vector<std::vector<uint32_t>> vect, uint32_t x, uint32_t y) {

  if(vect[x][y] == WALL)
    return 4;

  uint32_t n_wall = 0;
  n_wall += (vect[x-1][y] == WALL) ? 1 : 0;
  n_wall += (vect[x+1][y] == WALL) ? 1 : 0;
  n_wall += (vect[x][y-1] == WALL) ? 1 : 0;
  n_wall += (vect[x][y+1] == WALL) ? 1 : 0;
  return n_wall;
}

int32_t thing_around(std::vector<std::vector<uint32_t>> vect, uint32_t x, uint32_t y, uint32_t thing) {
  if(vect[x][y] == thing)
    return -1;

  uint32_t n_wall = 0;
  n_wall += (vect[x-1][y] == thing) ? 1 : 0;
  n_wall += (vect[x+1][y] == thing) ? 1 : 0;
  n_wall += (vect[x][y-1] == thing) ? 1 : 0;
  n_wall += (vect[x][y+1] == thing) ? 1 : 0;
  return n_wall;
}


std::vector<std::vector<uint32_t>> add_somethingfun(std::vector<std::vector<uint32_t>> vect){

  //* 0 - 8 traps
  //* 0 - 4 hostages

  //* In maze, 1 for hole, 0 for wall, 2 for solution

  //* output specs
  //* 0 for wall
  //* 1 for path
  //* 2 for traps
  //* 3 for hostages


  // srand(time(NULL));
  uint32_t traps = rand() % (8 - 0 + 1) + 0;
  uint32_t hostages = rand() % (4 - 0 + 1) + 0;

  uint32_t traps_o = traps;
  uint32_t hosttages_o = hostages;

  std::cout << "Traps: " << traps << std::endl;
  std::cout << "Host: " << hostages << std::endl;

  double trap_p;
  double host_p;



  std::vector<std::vector<uint32_t>> dead_end;
  std::vector<std::vector<uint32_t>> trap_locs;

  std::vector<std::vector<uint32_t>> new_maze;

  // for(std::size_t i=1;i<vect.size()-1;i++) {
  //   std::vector<uint32_t> tmp;
  //   for(std::size_t j=1;j<vect[0].size()-1;j++) {
  //     tmp.push_back(vect[i][j]);
  //   }
  //   new_maze.push_back(tmp);
  // }

  for(std::size_t i=1;i<vect.size()-1;i++) {
    for(std::size_t j=1;j<vect[0].size()-1;j++) {

      if(((i == 1 && j == 1) || (i == vect.size()-2 && j == vect[0].size()-2)))
        continue;

      if(wall_around(vect, i, j) == 3 ){
        std::vector<uint32_t> t;
        t.push_back(i);
        t.push_back(j);
        dead_end.push_back(t);
        // hostages--;
      }

      //* each trap would have two walls around it
      if(wall_around(vect, i, j) == 2 && thing_around(vect, i, j, TRAP) == 0 ) { //* potential trap loc
        std::vector<uint32_t> t;
        t.push_back(i);
        t.push_back(j);
        trap_locs.push_back(t);
        // traps--;
      }
    }
  }

  std::vector<uint32_t> traps_pos;
  uint32_t t = traps_o;
  while(t--) {

    uint32_t len = trap_locs.size();
    uint32_t p = rand() % (len-1 - 0 + 1) + 0;

    uint32_t i, j;
    i = trap_locs[p][0];
    j = trap_locs[p][1];

    traps_pos.push_back(i);
    traps_pos.push_back(j);
    if(thing_around(vect, i, j, TRAP) == 0)
      vect[i][j] = TRAP;
    std::vector<std::vector<uint32_t>>::iterator it;
    it = trap_locs.begin() + p;
    trap_locs.erase(it);
  }

  std::vector<uint32_t> host_pos;
  t = hosttages_o;
  while(t--) {
    uint32_t len = dead_end.size();

    uint32_t p = rand() % (len-1 - 0 + 1) + 0;

    uint32_t i, j;
    i = dead_end[p][0];
    j = dead_end[p][1];

    host_pos.push_back(i);
    host_pos.push_back(j);

    if(vect[i][j] != HOST)
      vect[i][j] = HOST;
    std::vector<std::vector<uint32_t>>::iterator it;
    it = dead_end.begin() + p;
    dead_end.erase(it);
  }
  
  for(std::size_t i=1;i<vect.size()-1;i++) {
    std::vector<uint32_t> tmp;
    for(std::size_t j=1;j<vect[0].size()-1;j++) {
      tmp.push_back(vect[i][j]);
    }
    new_maze.push_back(tmp);
  }





  return new_maze;

}



std::vector<std::vector<uint32_t>> output_maze(std::vector<std::vector<uint32_t>> vect, std::string filename) {

  //* 0 - 8 traps
  //* 0 - 4 hostages

  //* In maze, 1 for hole, 0 for wall, 2 for solution

  //* output specs
  //* 0 for wall
  //* 1 for path
  //* 2 for traps
  //* 3 for hostages

  std::fstream file;

  

  // srand(time(NULL));
  uint32_t traps = rand() % (8 - 0 + 1) + 0;
  uint32_t hostages = rand() % (4 - 0 + 1) + 0;

  uint32_t traps_o = traps;
  uint32_t hosttages_o = hostages;

  std::cout << "Traps: " << traps << std::endl;
  std::cout << "Host: " << hostages << std::endl;

  double trap_p;
  double host_p;



  std::vector<std::vector<uint32_t>> dead_end;
  std::vector<std::vector<uint32_t>> trap_locs;

  std::vector<std::vector<uint32_t>> new_maze;

  // for(std::size_t i=1;i<vect.size()-1;i++) {
  //   std::vector<uint32_t> tmp;
  //   for(std::size_t j=1;j<vect[0].size()-1;j++) {
  //     tmp.push_back(vect[i][j]);
  //   }
  //   new_maze.push_back(tmp);
  // }

  for(std::size_t i=1;i<vect.size()-1;i++) {
    for(std::size_t j=1;j<vect[0].size()-1;j++) {

      if(((i == 1 && j == 1) || (i == vect.size()-2 && j == vect[0].size()-2)))
        continue;

      if(wall_around(vect, i, j) == 3 ){
        std::vector<uint32_t> t;
        t.push_back(i);
        t.push_back(j);
        dead_end.push_back(t);
        // hostages--;
      }

      //* each trap would have two walls around it
      if(wall_around(vect, i, j) == 2 && thing_around(vect, i, j, TRAP) == 0 ) { //* potential trap loc
        std::vector<uint32_t> t;
        t.push_back(i);
        t.push_back(j);
        trap_locs.push_back(t);
        // traps--;
      }
    }
  }

  std::vector<uint32_t> traps_pos;

  uint32_t t = traps_o;
  while(t--) {

    uint32_t len = trap_locs.size();
    uint32_t p = rand() % (len-1 - 0 + 1) + 0;

    uint32_t i, j;
    i = trap_locs[p][0];
    j = trap_locs[p][1];

    traps_pos.push_back(i);
    traps_pos.push_back(j);
    if(thing_around(vect, i, j, TRAP) == 0)
      vect[i][j] = TRAP;
    std::vector<std::vector<uint32_t>>::iterator it;
    it = trap_locs.begin() + p;
    trap_locs.erase(it);
  }

  std::vector<uint32_t> host_pos;
  t = hosttages_o;
  while(t--) {
    uint32_t len = dead_end.size();

    uint32_t p = rand() % (len-1 - 0 + 1) + 0;

    uint32_t i, j;
    i = dead_end[p][0];
    j = dead_end[p][1];

    host_pos.push_back(i);
    host_pos.push_back(j);

    if(vect[i][j] != HOST)
      vect[i][j] = HOST;
    std::vector<std::vector<uint32_t>>::iterator it;
    it = dead_end.begin() + p;
    dead_end.erase(it);
  }
  
  for(std::size_t i=1;i<vect.size()-1;i++) {
    std::vector<uint32_t> tmp;
    for(std::size_t j=1;j<vect[0].size()-1;j++) {
      tmp.push_back(vect[i][j]);
    }
    new_maze.push_back(tmp);
  }


  std::vector<int32_t> ans_vec;
  maze::file_system m_file_system;
  m_file_system.raw_save(new_maze, filename);
  
  file.open(filename, std::ios::app | std::ios::ate);

  file << hosttages_o << std::endl;
  for(int i=0;i<hosttages_o;i++) {
    if(hosttages_o % 2 == 0 && hosttages_o != 0) {
      int32_t r = rand() % ( 99 - (-99) + 1 ) + (-99);
      file << r << " ";
      ans_vec.push_back(r);
    } else if(hosttages_o % 2 != 0){
      int32_t r = rand() % ( 255 - (-255) + 1 ) + (-255);
      file << r << " ";
      ans_vec.push_back(r);
    }
  }
  file << std::endl;
  ans_vec = ans(ans_vec); 

  for(int i=0;i<ans_vec.size();i++) {
    file << ans_vec[i] << " ";
  }
  file << std::endl;
  file.close();



  return new_maze;


}


std::vector<int32_t> ans(std::vector<int32_t> vect) {


    

    if( vect.size() % 2 == 0 && vect.size() != 0) {
      for(int i=0;i<vect.size();i++){
        int sign = vect[i] < 0 ? 1 : 0;
        vect[i] = sign ? ~vect[i]+1 : vect[i];
        int upper = (vect[i]/10) % 10;
        int lower = vect[i] % 10;

        upper = (upper + 3 ) & 0xf;
        lower = (lower + 3) & 0xf;
        vect[i] = (((upper) << 4) | lower) & 0xff;

        vect[i] = sign ? (vect[i] | (1 << 8)) : vect[i];
        vect[i] = sign ? (vect[i] << 23) >>23 : vect[i];
      }
    }
    std::sort(vect.begin(), vect.end(), [](int32_t x, int32_t y) {
        return x > y;
    });

    for(int i=0;i<vect.size();i++){
      std::cout << vect[i] << " " ;
    }
    std::cout << std::endl;

    if( vect.size() % 2 == 0 && vect.size() != 0) {
      for(int i=0;i<vect.size();i++){
        int sign = vect[i] < 0 ? 1 : 0;
        int upper = ((vect[i] >> 4 ) & 0xf) - 3;
        int lower = ((vect[i]) & 0xf) - 3;
        vect[i] = sign ? -(upper*10 + lower) : (upper*10 + lower);
      }
    }

  for(int i=0;i<vect.size();i++){
      std::cout << vect[i] << " " ;
    }
    std::cout << std::endl;

  if(vect.size() > 1) {

    int max = vect[0];
    int min = vect[vect.size()-1];

    int rng = (max + min) / 2;
    for(int i=0;i<vect.size();i++) {
      vect[i] -= rng;
    }

  }
  for(int i=0;i<vect.size();i++){
      std::cout << vect[i] << " " ;
    }

    std::cout << std::endl;

  if(vect.size() > 2) {
    for(int i=0;i<vect.size();i++) {

      if(i == 0)
        vect[i] = (vect[i]*2+vect[i])/3;
      else {
        vect[i] = (vect[i-1] * 2 + vect[i] )/3;
      }
    }
  }
  for(int i=0;i<vect.size();i++){
      std::cout << vect[i] << " " ;
    }

    std::cout << std::endl;


  return vect;
  

}


std::vector<std::vector<uint32_t>> output_maze_corner(std::vector<std::vector<uint32_t>> vect, std::string filename, int32_t hostages, int32_t traps) {

  //* 0 - 8 traps
  //* 0 - 4 hostages

  //* In maze, 1 for hole, 0 for wall, 2 for solution

  //* output specs
  //* 0 for wall
  //* 1 for path
  //* 2 for traps
  //* 3 for hostages

  std::fstream file;

  

  // srand(time(NULL));
  // uint32_t traps = rand() % (8 - 0 + 1) + 0;
  // uint32_t hostages = rand() % (4 - 0 + 1) + 0;

  uint32_t traps_o = traps;
  uint32_t hosttages_o = hostages;

  std::cout << "Traps: " << traps << std::endl;
  std::cout << "Host: " << hostages << std::endl;

  double trap_p;
  double host_p;



  std::vector<std::vector<uint32_t>> dead_end;
  std::vector<std::vector<uint32_t>> trap_locs;

  std::vector<std::vector<uint32_t>> new_maze;

  // for(std::size_t i=1;i<vect.size()-1;i++) {
  //   std::vector<uint32_t> tmp;
  //   for(std::size_t j=1;j<vect[0].size()-1;j++) {
  //     tmp.push_back(vect[i][j]);
  //   }
  //   new_maze.push_back(tmp);
  // }

  for(std::size_t i=1;i<vect.size()-1;i++) {
    for(std::size_t j=1;j<vect[0].size()-1;j++) {

      if(((i == 1 && j == 1) || (i == vect.size()-2 && j == vect[0].size()-2)))
        continue;

      if(wall_around(vect, i, j) == 3 ){
        std::vector<uint32_t> t;
        t.push_back(i);
        t.push_back(j);
        dead_end.push_back(t);
        // hostages--;
      }

      //* each trap would have two walls around it
      if(wall_around(vect, i, j) == 2 && thing_around(vect, i, j, TRAP) == 0 ) { //* potential trap loc
        std::vector<uint32_t> t;
        t.push_back(i);
        t.push_back(j);
        trap_locs.push_back(t);
        // traps--;
      }
    }
  }

  std::vector<uint32_t> traps_pos;

  uint32_t t = traps_o;
  while(t--) {

    uint32_t len = trap_locs.size();
    uint32_t p = rand() % (len-1 - 0 + 1) + 0;

    uint32_t i, j;
    i = trap_locs[p][0];
    j = trap_locs[p][1];

    traps_pos.push_back(i);
    traps_pos.push_back(j);
    if(thing_around(vect, i, j, TRAP) == 0)
      vect[i][j] = TRAP;
    std::vector<std::vector<uint32_t>>::iterator it;
    it = trap_locs.begin() + p;
    trap_locs.erase(it);
  }

  std::vector<uint32_t> host_pos;
  t = hosttages_o;
  while(t--) {
    uint32_t len = dead_end.size();

    uint32_t p = rand() % (len-1 - 0 + 1) + 0;

    uint32_t i, j;
    i = dead_end[p][0];
    j = dead_end[p][1];

    host_pos.push_back(i);
    host_pos.push_back(j);

    if(vect[i][j] != HOST)
      vect[i][j] = HOST;
    std::vector<std::vector<uint32_t>>::iterator it;
    it = dead_end.begin() + p;
    dead_end.erase(it);
  }
  
  for(std::size_t i=1;i<vect.size()-1;i++) {
    std::vector<uint32_t> tmp;
    for(std::size_t j=1;j<vect[0].size()-1;j++) {
      tmp.push_back(vect[i][j]);
    }
    new_maze.push_back(tmp);
  }


  std::vector<int32_t> ans_vec;
  maze::file_system m_file_system;
  m_file_system.raw_save(new_maze, filename);
  
  // file.open(filename, std::ios::app | std::ios::ate);

  // file << hosttages_o << std::endl;
  // for(int i=0;i<hosttages_o;i++) {
  //   if(hosttages_o % 2 == 0 && hosttages_o != 0) {
  //     int32_t r = rand() % ( 99 - (-99) + 1 ) + (-99);
  //     file << r << " ";
  //     ans_vec.push_back(r);
  //   } else if(hosttages_o % 2 != 0){
  //     int32_t r = rand() % ( 255 - (-255) + 1 ) + (-255);
  //     file << r << " ";
  //     ans_vec.push_back(r);
  //   }
  // }

  // std::fstream ans_file = 

  // file << std::endl;
  // ans_vec = ans(ans_vec); 

  // for(int i=0;i<ans_vec.size();i++) {
  //   file << ans_vec[i] << " ";
  // }
  // file << std::endl;
  file.close();



  return new_maze;


}

