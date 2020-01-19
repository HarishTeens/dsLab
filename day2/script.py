function ttable(values)

  output = feval(@(y)feval(@(x)mod(ceil(repmat((1:x(1))', 1, numel(x) - 1) ./ repmat(x(2:end), x(1), 1)) - 1, repmat(fliplr(y), x(1), 1)) + 1, fliplr([1 cumprod(y)])), fliplr(values));
end
vertices = ttable(ones(1, 5) * 2) - 1
adj_list = zeros(2^5, 5)
adj_mat = zeros(2^5, 2^5)
for v=1:2^5
  L1_dists = sum(abs(vertices - repmat(vertices(v, :), 2^5, 1)), 2)
  adj_list(v, :) = find(L1_dists == 1)
  adj_mat(v, find(L1_dists == 1)) = 1
end