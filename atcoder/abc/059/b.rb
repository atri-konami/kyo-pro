a=gets.to_i
b=gets.to_i
puts case a <=> b
when 1
    'GREATER'
when 0
    'EQUAL'
when -1
    'LESS'
end

