# Title: HW5
# Author: Emily Addiego
# Due Date: 11/9/20
# Description: implementation of the babyfaces vs. heels algorithm reads wrestlers and rivalries from
# a text file and determines whether the wrestlers can be divided into two teams based on their rivalries.

# getEdges extracts information from the text file and sends to babyfacesVsHeels function
def getEdges():
# allow user to enter filename
    with open(input("Enter Filename: "),'r') as f:
# create empty array of edges
        rivalries = []
# skip through vertices
        n = f.readline()
        for i in range(0, int(n)):
            next(f)
        r = f.readline()
# read each rivalry pair into rivalries array
        for i in range(0, int(r)):
            pair = []
            x = f.readline()
            for w in x.split():
                pair.append(w)
            rivalries.append(pair)
        babyfacesVsHeels(rivalries)

# babyfacesVsHeels uses rivalries (edges) to determine whether wrestlers can be divided into
# two distinct teams
def babyfacesVsHeels(r):
# create two arrays for teams
    B = []
    H = []
    teams = True
    for i in range(0, len(r)):
# first case: vertex not discovered; assign to a team
        if r[i][0] not in B and r[i][0] not in H:
            if r[i][1] in B:
                H.append(r[i][0])
            elif r[i][1] in H:
                B.append(r[i][0])
# if both vertices are undiscovered, assign to opposite teams
            else:
                B.append(r[i][0])
                H.append(r[i][1])
# second case: vertex is in babyfaces
        elif r[i][0] in B:
            if r[i][1] not in B:
# if rival is in heels or unassigned, continue
                if r[i][1] in H:
                    continue
                else:
                    H.append(r[i][1])
# if rival is also in babyfaces, impossible to designate
            else:
                teams = False
                break
# third case: vertex is in heels
        elif r[i][0] in H:
            if r[i][1] not in H:
                if r[i][1] in B:
                    continue
                else:
                    B.append(r[i][1])
            else:
                teams = False
                break
    if teams == False:
        print("Impossible")
    else:
        print("Yes Possible")
        print("Babyfaces: " + ' '.join(str(x) for x in B))
        print("Heels: " + ' '.join(str(x) for x in H))


getEdges()
