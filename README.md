# maze-generator
A C++ library for maze generation.

## Dependencies
* Make

## Supported generation algorithms
* (Randomized depth-first search (backtracking))[https://en.wikipedia.org/wiki/Maze_generation_algorithm#Iterative_implementation]
* (Randomized Prim's algorithm)[https://en.wikipedia.org/wiki/Maze_generation_algorithm#Randomized_Prim's_algorithm]
* (Modified Prim's algorithm)[https://en.wikipedia.org/wiki/Maze_generation_algorithm#Modified_version]

## Usage
You can find the example in the _demos_ directory.
1. Include desired generator header
```cpp
#include "maze/prim_generator.h"
```
2. Create instance of generator class
```cpp
generator = std::make_unique<maze::RandomizedPrimGenerator>();
```
3. Initialize matrix
```cpp
if (!generator->Initialize(width, height))
  return 1;
```
4. Set the random seed
```cpp
generator->Randomize(seed);
```
5. Generate at specific start position
```cpp
generator->Run(maze::Position::FromExternal(0, 0));
```
6. Access generated matrix via _matrix_ method
```cpp
maze::Matrix& matrix = generator->matrix();
bool is_room = matrix.IsRoom(maze::Position(2,3));
```
For matrix positive X is right, positive Y is down.

## License
Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).

## Bug Reporting
Please log bugs under [Issues](https://github.com/Shtille/maze-generator/issues) on github.

## Disclaimer
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.