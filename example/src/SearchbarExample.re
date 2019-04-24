open BsReactNative;
open Navigation;
open BsReactNativePaper;
open Paper;

module Styles = {
  open Style;

  let container = style([flex(1.0), backgroundColor(String("#ededed"))]);
  let searchbar = style([margin(Pt(4.))]);
  let caption =
    style([paddingHorizontal(Pt(16.)), paddingVertical(Pt(8.))]);
};

type state = {
  firstQuery: string,
  secondQuery: string,
  thirdQuery: string,
};

type action =
  | FirstQueryChanged(string)
  | SecondQueryChanged(string)
  | ThirdQueryChanged(string);

let component = ReasonReact.reducerComponent("Searchbar Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {firstQuery: "", secondQuery: "", thirdQuery: ""},
  reducer: (action, state) =>
    switch (action) {
    | FirstQueryChanged(text) =>
      ReasonReact.Update({...state, firstQuery: text})
    | SecondQueryChanged(text) =>
      ReasonReact.Update({...state, secondQuery: text})
    | ThirdQueryChanged(text) =>
      ReasonReact.Update({...state, thirdQuery: text})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Searchbar example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Searchbar
                 placeholder="Search"
                 onChangeText={query => self.send(FirstQueryChanged(query))}
                 value={self.state.firstQuery}
                 style=Styles.searchbar
               />
               <Caption style=Styles.caption>
                 {ReasonReact.string("Clickable icon")}
               </Caption>
               <Searchbar
                 placeholder="Search"
                 onChangeText={query => self.send(SecondQueryChanged(query))}
                 value={self.state.secondQuery}
                 onIconPress={_event => navigation.pop()}
                 icon={Icon.Name("arrow-back")}
                 style=Styles.searchbar
               />
               <Searchbar
                 placeholder="Search"
                 onChangeText={query => self.send(ThirdQueryChanged(query))}
                 value={self.state.thirdQuery}
                 onIconPress={_event => ()}
                 icon={
                   Icon.Element(
                     Icon.renderIcon((props: Icon.iconProps) =>
                       <RNIcons.MaterialIcons
                         name=`_menu
                         size={props.size}
                         color={props.color}
                       />
                     ),
                   )
                 }
                 style=Styles.searchbar
               />
             </View>
         }
    </StackNavigator.Screen>,
};
