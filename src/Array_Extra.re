let last = arr => Belt_Array.get(arr, Belt_Array.length(arr) - 1);

let toMatrix = (columns, arr) =>
  Belt_Array.reduce(arr, [|[||]|], (matrix, item) =>
    switch (last(matrix)) {
    | Some(row) =>
      Belt_Array.length(row) == columns
        ? Belt_Array.concat(matrix, [|[|item|]|])
        : {
          Belt_Array.set(
            matrix,
            Belt_Array.length(matrix) - 1,
            Belt_Array.concat(row, [|item|]),
          )
          |> ignore;

          matrix;
        }
    | _ => matrix
    }
  );
