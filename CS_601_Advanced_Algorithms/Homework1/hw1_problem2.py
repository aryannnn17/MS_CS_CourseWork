from collections import deque

def stable_matching(residents, hospitals, hospital_quotas):
    # Initialize all residents as unmatched
    resident_matches = {r: None for r in residents}  
    hospital_matches = {h: [] for h in hospitals}  
    proposals = {r: deque(residents[r]) for r in residents}  # Queue of preferences for each resident
    
    unmatched_residents = deque(residents.keys())  # Residents who are still looking for a match

    while unmatched_residents:
        resident = unmatched_residents.popleft()

        while proposals[resident]:  # While the resident has hospitals left to propose to
            hospital = proposals[resident].popleft()

            if resident in hospitals[hospital]:  # Only propose if the hospital recognizes the resident
                hospital_matches[hospital].append(resident)
                resident_matches[resident] = hospital

                # If hospital exceeds quota, reject the least preferred resident
                if len(hospital_matches[hospital]) > hospital_quotas[hospital]:
                    ranked_residents = sorted(hospital_matches[hospital], key=lambda r: hospitals[hospital].index(r))
                    rejected_resident = ranked_residents.pop()  # Remove lowest-ranked resident
                    
                    hospital_matches[hospital] = ranked_residents
                    resident_matches[rejected_resident] = None
                    
                    unmatched_residents.append(rejected_resident)  # Re-add to unmatched list
                break  # Move to the next resident
    
    return resident_matches

# Example Test Case
residents = {
    'A': ['X', 'Y', 'Z'],
    'B': ['Y', 'X', 'Z'],
    'C': ['X', 'Z', 'Y'],
}
hospitals = {
    'X': ['A', 'B', 'C'],
    'Y': ['B', 'A', 'C'],
    'Z': ['C', 'B', 'A'],
}
hospital_quotas = {'X': 1, 'Y': 1, 'Z': 1}

matching = stable_matching(residents, hospitals, hospital_quotas)
print("Final Matching:", matching)
