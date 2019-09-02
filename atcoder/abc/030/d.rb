class Node
    attr_accessor :here,:to
    def initialize
        @here = -1
        @to = -1
    end
end

n,a = gets.chomp.split.map(&:to_i)

k = gets.chomp.to_i

dict= Array.new(n+1)

for i in 1..n
    dict[i] = Node.new
end

v=[]

aa = gets.chomp.split.map(&:to_i)

for i in 1..n 
    dict[i].to = aa[i-1]
end

b=0

while true
    b = dict[a].to
    break if dict[b].here != -1
    v << b
    dict[b].here = v.size-1
    a=b
end

k -= dict[b].here
mod = v.size-dict[b].here

puts v[k%mod+dict[b].here-1]




