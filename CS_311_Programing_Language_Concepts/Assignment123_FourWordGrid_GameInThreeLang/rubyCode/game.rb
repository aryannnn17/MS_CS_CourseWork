# CS_311_PLC_Assignment03
# Author : Aryan Jigneshbhai Bhagat
# NetID: sl5310
# Teammate: Venkata Sai Krishna Aditya Vatturi
# Teammate NetID: by4412
# Contribution: I've worked on the code part and brainstorming part along with my teammate, he helped me in testing and verifying different cases
# Date: 10/03/2024

dictionary = []
# make sure you include the correct file path
File.open('dictionary.txt') do |dataFile| 
  for word in dataFile.readlines()
    dictionary.push(word)
  end
end

random_selected_words = dictionary.sample(4);

letters= []
for words in random_selected_words
  for i in 0...4
    letters.push(words[i])
  end
  # print words 
end

shuffled_letters = letters.shuffle

print "\n<<<<<<<<<<<<<<<  GAME->FOUR_WORD_GRID  >>>>>>>>>>>>>>>>>>>>\n";

for i in 0...16
  if(i%4==0)
    print "\n                      "
  end
  print shuffled_letters.at(i)
  print "  "
end

puts
puts

lives = 3  
while (lives > 0)
  lives -= 1
  word_count = 4
  count = 0
  user_list = []

  while (word_count > 0)
    word_count -= 1
    print "Enter Word #{4 - word_count}: "
    user_word = gets
    check = user_list.include?(user_word)
    while check
      puts "You've already entered this word before, enter a different one"
      print "Enter Word #{4 - word_count}: "
      user_word = gets
      check = user_list.include?(user_word)
    end
    user_list.push(user_word)
    
    if random_selected_words.map(&:strip).include?(user_word.strip)
      count += 1
    end
  end

  if count == 4
    puts "\n<<<<<<<<<<<  CONGRATULATIONS! YOU'RE THE WINNER  >>>>>>>>>>>>\n\n"
    exit(0)
  end

  if lives == 0
    break
  end

  puts "\nSorry! These are not the correct words!"
  puts "Now, You have only #{lives} lives remaining!\n"
end

print "\nThe correct 4 words are: "
puts random_selected_words.join(", ")
puts "\n<<<<<<<<<<<  YOUR ALL LIVES ARE OVER! BETTER LUCK NEXT TIME!  >>>>>>>>>>>>\n\n"

