r = gets.chomp
onkai = {5 => 'Do', 3 => 'Re', 1 => 'Mi', 0 => 'Fa', 10 => 'So', 8 => 'La', 6 => 'Si'}

index = r.index("WBWBWBW")

puts onkai[index]


