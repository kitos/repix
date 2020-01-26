open Fetch;
open Js_promise;

type character = {
  id: int,
  name: string,
  gender: string,
  image: string,
};

type response = {results: array(character)};

module Decode = {
  let hero = json =>
    Json.Decode.{
      id: json |> field("id", int),
      name: json |> field("name", string),
      gender: json |> field("gender", string),
      image: json |> field("image", string),
    };

  let response = json =>
    Json.Decode.{results: json |> field("results", array(hero))};
};

let getCharecters = () =>
  fetchWithInit(
    "https://rickandmortyapi.com/api/character/",
    RequestInit.make(
      ~headers=HeadersInit.make({"Content-Type": "application/json"}),
      (),
    ),
  )
  |> then_(Response.json)
  |> then_(r => r |> Decode.response |> (r => r.results |> resolve));
