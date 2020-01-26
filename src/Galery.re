open ReactNative;
open Js_promise;
open Array_Extra;
open Api;

let const = (i, _) => i;

let styles =
  Style.(
    StyleSheet.create({
      "image": style(~width=100.->dp, ~height=120.->dp, ()),
      "row":
        viewStyle(
          ~flex=1.,
          ~flexDirection=`row,
          ~justifyContent=`spaceAround,
          ~marginBottom=30.->dp,
          (),
        ),
    })
  );

[@react.component]
let make = () => {
  let (images, setImages) = React.useState(() => [||]);

  React.useEffect(() => {
    getCharecters()
    |> then_(r => r |> toMatrix(3) |> const |> setImages |> resolve)
    |> ignore;

    None;
  });

  <FlatList
    keyExtractor={(_, i) => i->string_of_int}
    data=images
    renderItem={i =>
      <View key={string_of_int(i##index)} style=styles##row>
        {i##item
         ->Belt_Array.map(char =>
             <View key={string_of_int(char.id)}>
               <Image
                 style=styles##image
                 source={Image.Source.fromUriSource(
                   Image.uriSource(~uri=char.image, ()),
                 )}
               />
             </View>
           )
         ->React.array}
      </View>
    }
  />;
};
