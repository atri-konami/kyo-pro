class UnionFind
    def initialize(n)
        @par = [*0...n]
        @rnk = [0]*n
    end

    def find(x)
        return x if @par[x] == x
        @par[x] = find(@par[x])
    end

    def same(x,y)
        find(x) == find(y)
    end

    def unite(x,y)
        x=find(x);y=find(y)
        return if x==y

        if @rnk[x] < @rnk[y]
            @par[x] = y
        elsif
            @par[y] = x
            @rnk[x]+=1 if @rnk[x]==@rnk[y]
        end
    end
end

n,q = gets.chomp.split.map(&:to_i)
u = UnionFind.new(n)

1.upto(q){
    p,a,b = gets.chomp.split.map(&:to_i)
    if p==0
        u.unite(a,b)
    else
        puts u.same(a,b) ? "Yes" : "No"
    end
}
