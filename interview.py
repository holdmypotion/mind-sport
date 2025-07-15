from collections import defaultdict, deque

source = "1000"
dest = "9555"
states = ["7000", "7500", "9000", "9500", "9550", "9555"]
NUM_OF_DIGITS = 4
 
 
def is_valid_state_transition(src: str, dest: str) -> bool:
    diff = 0
    for i in range(NUM_OF_DIGITS):
        if src[i] != dest[i]:
            diff += 1
    
    return diff == 1


def minimum_transitions_to_reach_projected_state(source, destination, states):
    states.append(source)
    states = list(set(states))
    
    number_of_states = len(states)
    adj = defaultdict(list)
    
    for src in states:
        for dest in states:
            if src != dest and is_valid_state_transition(src, dest):
                adj[src].append(dest)
    
    vis = defaultdict(bool)
    vis[source] = True
    level = 0
    
    q = deque([source])
    
    while q:
        for i in range(len(q)):
            node = q.popleft()
            if node == destination:
                return level
            
            for neigh in adj[node]:
                if not vis[neigh]:
                    q.append(neigh)
                    vis[neigh] = True
        
        level += 1
    
    return -1


print(minimum_transitions_to_reach_projected_state(source, dest, states))

