open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0), margin(Pt(10.))]);

  let contentContainerStyle =
    style([flexDirection(Row), flexWrap(Wrap), padding(Pt(4.))]);

  let image = style([flex(1.), resizeMode(Cover)]);

  let item =
    style([
      height(Pt(float_of_int(Dimensions.get(`window)##width / 2))),
      width(Pct(50.)),
      padding(Pt(4.)),
    ]);
};

let renderScene =
  BottomNavigation.renderSceneType((props: BottomNavigation.renderSceneProps) => {
    let photos =
      Array.make(24, "https://unsplash.it/300/300/?random&__id=")
      |> Array.mapi((index, element) =>
           element ++ props.route.key ++ string_of_int(index)
         );

    <ScrollView contentContainerStyle=Styles.contentContainerStyle>
      {
        photos
        |> Array.map(uri =>
             <View key=uri style=Styles.item>
               <Image
                 source={URI(Image.imageURISource(~uri, ()))}
                 style=Styles.image
               />
             </View>
           )
        |> ReasonReact.array
      }
    </ScrollView>;
  });

type state = {index: int};

type action =
  | IndexChanged(int);

let component = ReasonReact.reducerComponent("BottomNavigationExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {index: 0},
  reducer: (action, _state) =>
    switch (action) {
    | IndexChanged(index) => ReasonReact.Update({index: index})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="BottomNavigation example" navigation>
      ...{
           () =>
             <BottomNavigation
               onIndexChange={index => self.send(IndexChanged(index))}
               navigationState={
                 BottomNavigation.createNavigationState(
                   ~index=self.state.index,
                   ~routes=[|
                     BottomNavigation.route(
                       ~key="Album",
                       ~title="Album",
                       ~icon=Icon.Name("photo-album"),
                       ~color="#6200ee",
                       (),
                     ),
                     BottomNavigation.route(
                       ~key="Library",
                       ~title="Library",
                       ~icon=Icon.Name("inbox"),
                       ~color="#2962ff",
                       (),
                     ),
                     BottomNavigation.route(
                       ~key="Favorites",
                       ~title="Favorites",
                       ~icon=Icon.Name("favorite"),
                       ~color="#00796b",
                       (),
                     ),
                     BottomNavigation.route(
                       ~key="Purchased",
                       ~title="Purchased",
                       ~icon=Icon.Name("shop"),
                       ~color="#c51162",
                       (),
                     ),
                   |],
                 )
               }
               renderScene
               shifting=true
             />
         }
    </StackNavigator.Screen>,
};
