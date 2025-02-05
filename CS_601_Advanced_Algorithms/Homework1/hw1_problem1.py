def count_unhappy_friends(n, pref, pairs):
    pair_map = {x: y for x, y in pairs}
    pair_map.update({y: x for x, y in pairs})
    
    rank = {i: {p: idx for idx, p in enumerate(pref[i])} for i in range(n)}
    
    unhappy_count = 0
    
    for x in range(n):
        y = pair_map[x]
        for a in pref[x]:
            if a == y:
                break  # Stop if we reach the current partner
            b = pair_map[a]
            if rank[a][x] < rank[a][b]: 
                unhappy_count += 1 # update unhappy count 
                break
    
    return unhappy_count

# Test cases
test_cases = [
    # Four Test Cases - which are already given
    (4, [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], [[0, 1], [2, 3]]),
    (2, [[1], [0]], [[1, 0]]),
    (4, [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]], [[1, 3], [0, 2]]),
    (4, [[1, 3, 2], [2, 3, 0], [1, 0, 3], [1, 0, 2]], [[2, 1], [3, 0]]),
    
    # Extra Test Case
    (4, [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], [[0, 2], [1, 3]]),
    
]

for n, pref, pairs in test_cases:
    print(f"Unhappy friends count: {count_unhappy_friends(n, pref, pairs)}")