#include "counters/brute_counter.h"

#include <cassert>
#include <functional>
#include <unordered_set>
#include <utility>

using namespace std;

namespace counters {

namespace {

struct PairHash {
  std::size_t operator()(const std::pair<int, int>& p) const {
    auto h1 = std::hash<int>{}(p.first);
    auto h2 = std::hash<int>{}(p.second);

    return h1 ^ h2;
  }
};

using Point = pair<int, int>;
using PointSet = unordered_set<Point, PairHash>;

int digitSum(int x) {
  assert(x >= 0);

  int res = 0;
  while (x > 0) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

bool isAvailablePoint(const Point& p, int deepness) {
  return p.first >= 0 && p.second >= 0 &&
         digitSum(p.first) + digitSum(p.second) <= deepness;
}

bool isAvailableMovement(const Point& p, int deepness, const PointSet& visited,
                         const PointSet& active) {
  if (!isAvailablePoint(p, deepness)) return false;

  if (active.find(p) != active.end()) return false;

  return visited.find(p) == visited.end();
}

}  // namespace

long long brute_force(int init_x, int init_y, int deepness) {
  auto init_point = make_pair(init_x, init_y);
  if (!isAvailablePoint(init_point, deepness)) {
    return 0;
  }

  PointSet visited;
  PointSet active{std::move(init_point)};

  do {
    PointSet new_active;
    for (const auto& p : active) {
      Point moves[4]{{p.first, p.second - 1},
                     {p.first, p.second + 1},
                     {p.first - 1, p.second},
                     {p.first + 1, p.second}};

      for (const auto& m : moves)
        if (isAvailableMovement(m, deepness, visited, active))
          new_active.insert(m);
    }

    visited.merge(std::move(active));
    active = std::move(new_active);
  } while (active.size() != 0);

  return visited.size();
}

}  // namespace counters