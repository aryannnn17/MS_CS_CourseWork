# Name: Aryan Jigneshbhai Bhagat
# NetID: sl5310
# Email: abhagat4@horizon.csueastbay.edu

#<<<<---- CS_667_Machine_Leaning - Coding_Assignment: Genetic Algorithm ------->>>>>>>

import numpy as np
import math

def init_population(populationSize, bounds):
    return np.random.uniform(bounds[0], bounds[1], (populationSize, 2))

def selection(population, fitness_values, num_parents):
    sorted_indices = np.argsort(fitness_values)[::-1]
    parents = population[sorted_indices[:num_parents]]
    return parents

def fitness(x, y):
    return (1 - x) ** 2 * np.exp(-x ** 2 - (y + 1) ** 2) - (x - x ** 3 - y ** 3) * np.exp(-x ** 2 - y ** 2)

def evalfitness(population):
    return [fitness(x, y) for x, y in population]

def crossover(parents, crossoverProb):
    offspring = []
    for i in range(0, len(parents), 2):
        parent1, parent2 = parents[i], parents[i + 1]
        if np.random.rand() < crossoverProb:
            crossover_point = np.random.randint(1, len(parent1))
            child1 = np.concatenate((parent1[:crossover_point], parent2[crossover_point:]))
            child2 = np.concatenate((parent2[:crossover_point], parent1[crossover_point:]))
            offspring.append(child1)
            offspring.append(child2)
        else:
            offspring.append(parent1)
            offspring.append(parent2)
    return np.array(offspring)

def mutation(offspring, mutationProb, bounds):
    for i in range(len(offspring)):
        if np.random.rand() < mutationProb:
            gene = np.random.randint(0, len(offspring[i]))
            offspring[i][gene] = np.random.uniform(bounds[0], bounds[1])
    return offspring

def geneticAlgorithm(populationSize, generationsNumbers, crossoverProb, mutationProb, bounds):
    population = init_population(populationSize, bounds)

    for generation in range(generationsNumbers):
        fitness_values = evalfitness(population)
        parents = selection(population, fitness_values, populationSize // 2)
        offspring = crossover(parents, crossoverProb)
        offspring = mutation(offspring, mutationProb, bounds)
        population = np.concatenate((parents, offspring))

    best_index = np.argmax(fitness_values)
    X, Y = population[best_index]
    fitness = fitness_values[best_index]
    return X, Y, fitness


populationSize = 8
generationsNumbers = 200
crossoverProb = 0.7
mutationProb = 0.01
bounds = (-2, 2)

X, Y, fitness = geneticAlgorithm(populationSize, generationsNumbers, crossoverProb, mutationProb,
                                                 bounds)
print(f"optimal [x, y] pair is: ({X:.3f}, {Y:.3f})")
print(f"maximum fitness value is: {fitness:.3f}")