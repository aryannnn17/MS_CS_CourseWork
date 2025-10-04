# Python implementation of stable matching problem
# Modified based on Tyler Moore's implementation


def gale_shapley(hospital, student, pref_hospital, pref_student):
    # inverse student prereference list  
    # for each student keep the rank for each man, rank_hospital is a dictionary of dicionary, 
    # when w needs to choose, we can compare the rank of each man with constant time
    # the bigger the number, the higher the rank
    rank_hospital = {}
    for s in student:
        rank_hospital[s] = {} 
        i = len(hospital)
        for h in pref_student[s]:
            rank_hospital[s][h] = i # the higher the number (which is i) is,the higher the ranking
            i -= 1
    # print(rank_hospital)
    # count how many proposals each hospital has made, to track next student he can propose
    count = {}
    for h in hospital:
        count[h] = 0

    

    freehospital = list(hospital)    # initially all hospital and student are free
    numpartners = len(student) 
    M = {}           # engaged pairs stored in dictionary with student name as key, hospital name as value

    #run the algorithm
    while freehospital:
        h = freehospital.pop()
        if count[h] > numpartners: continue
        # get the first student that h has not yet been proposed to
        s = pref_hospital[h][count[h]]
        count[h] += 1
        # print(count)

        if s not in M: # student s is free
            M[s] = h
        else:
            # s prefers h to the current partner h', accepts h, dumps h'
            hprime = M[s]
            if rank_hospital[s][h] > rank_hospital[s][hprime]:
                M[s] = h # M = {...,"wayne":"Chicago",..}
                freehospital.append(hprime)
            # s prefers the current partner, reject h
            else:
                freehospital.append(h)
    return M

if __name__=="__main__":
    
    # change to a data structure (e.g a dictionay) to keep track the number of positions for each hospital
    hospital = ['Atlanta', 'Boston', 'Chicago', 'Detroit', 'El Paso'] 
    student = ['Val', 'Wayne', 'Xavier', 'Yolanda', 'Zeus']


    pref_hospital = {'Atlanta': ['Wayne', 'Val', 'Yolanda', 'Zeus', 'Xavier'],
            'Boston': ['Yolanda', 'Wayne', 'Val', 'Xavier', 'Zeus'],
            'Chicago': ['Wayne','Zeus', 'Xavier','Yolanda', 'Val' ],
           'Detroit': ['Val', 'Yolanda','Xavier', 'Wayne', 'Zeus'],
           'El Paso': ['Wayne', 'Yolanda', 'Val', 'Zeus', 'Xavier']
           }
    pref_student = {
            'Val': ['El Paso', 'Atlanta', 'Boston', 'Detroit', 'Chicago'],
           'Wayne': ['Chicago', 'Boston', 'Detroit', 'Atlanta', 'El Paso'],
           'Xavier': ['Boston',  'Chicago', 'Detroit', 'El Paso', 'Atlanta'],
           'Yolanda': ['Atlanta', 'El Paso', 'Detroit', 'Chicago', 'Boston'],
           'Zeus': ['Detroit', 'Boston', 'El Paso', 'Chicago', 'Atlanta']
           }
 # for homework question: m hospitals, each h certain number of slots available 2, # n students, 
 # total number slots 2m < n => m < n.
 
    # hospital = ['Atlanta', 'Boston', 'Chicago'] 
    # num_slots_hopital = {'Atlanta': 1, 'Boston': 2 , 'Chicago': 1}
    # pref_hospital = {'Atlanta': ['Wayne', 'Val', 'Yolanda', 'Zeus', 'Xavier'],
    #             'Boston': ['Yolanda', 'Wayne', 'Val', 'Xavier', 'Zeus'],
    #             'Chicago': ['Wayne','Zeus', 'Xavier','Yolanda', 'Val' ]
    #            }

    # pref_student = {
    #         'Val': ['El Paso', 'Atlanta', 'Chicago'],
    #        'Wayne': ['Atlanta', 'El Paso', 'Chicago'],
    #        'Xavier': ['El Paso', 'Atlanta'],
    #        'Yolanda': ['Atlanta', 'El Paso'],
    #        'Zeus': ['El Paso', 'Atlanta']
    #        }
    stable_matching = gale_shapley(hospital,student, pref_hospital, pref_student)
    print(stable_matching)
