open BsReactNative;
open Navigation;
open Paper;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.0),
      backgroundColor(String("#ffffff")),
      paddingVertical(Pt(8.)),
    ]);

  let row =
    style([
      flexDirection(Row),
      alignItems(Center),
      justifyContent(SpaceBetween),
      paddingVertical(Pt(8.)),
      paddingHorizontal(Pt(16.)),
    ]);

  let bottomStyle =
    style([
      position(Absolute),
      left(Pt(0.)),
      right(Pt(0.)),
      bottom(Pt(0.)),
    ]);

  let fab = style([position(Absolute), right(Pt(16.)), bottom(Pt(28.))]);
};

type state = {
  showLeftIcon: bool,
  showSubtitle: bool,
  showSearchIcon: bool,
  showMoreIcon: bool,
};

type action =
  | ToggleLeftIcon
  | ToggleSubtitle
  | ToggleSearchIcon
  | ToggleMoreIcon;

let component = ReasonReact.reducerComponent("Appbar Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {
    showLeftIcon: true,
    showSubtitle: true,
    showSearchIcon: true,
    showMoreIcon: true,
  },
  reducer: (action, state) =>
    switch (action) {
    | ToggleLeftIcon =>
      ReasonReact.Update({...state, showLeftIcon: !state.showLeftIcon})
    | ToggleSubtitle =>
      ReasonReact.Update({...state, showSubtitle: !state.showSubtitle})
    | ToggleSearchIcon =>
      ReasonReact.Update({...state, showSearchIcon: !state.showSearchIcon})
    | ToggleMoreIcon =>
      ReasonReact.Update({...state, showMoreIcon: !state.showMoreIcon})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Appbar example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Appbar.Header>
                 {
                   self.state.showLeftIcon ?
                     <Appbar.BackAction
                       onPress={_event => navigation.pop()}
                     /> :
                     ReasonReact.null
                 }
                 <Appbar.Content
                   title={ReasonReact.string("Appbar example")}
                   subtitle={
                     self.state.showSubtitle ?
                       ReasonReact.string("Subtitle") : ReasonReact.null
                   }
                 />
                 {
                   self.state.showSearchIcon ?
                     <Appbar.Action
                       icon={Icon.Name("search")}
                       onPress={() => ()}
                     /> :
                     ReasonReact.null
                 }
                 {
                   self.state.showMoreIcon ?
                     <Appbar.Action
                       icon={
                         Icon.Name(
                           switch (Platform.os()) {
                           | Android => "more-vert"
                           | _ => "more-horiz"
                           },
                         )
                       }
                       onPress={() => ()}
                     /> :
                     ReasonReact.null
                 }
               </Appbar.Header>
               <View style=Styles.row>
                 <Paragraph> {ReasonReact.string("Left icon")} </Paragraph>
                 <Switch
                   value={self.state.showLeftIcon}
                   onValueChange={_event => self.send(ToggleLeftIcon)}
                 />
               </View>
               <View style=Styles.row>
                 <Paragraph> {ReasonReact.string("Subtitle")} </Paragraph>
                 <Switch
                   value={self.state.showSubtitle}
                   onValueChange={_event => self.send(ToggleSubtitle)}
                 />
               </View>
               <View style=Styles.row>
                 <Paragraph> {ReasonReact.string("Search icon")} </Paragraph>
                 <Switch
                   value={self.state.showSearchIcon}
                   onValueChange={_event => self.send(ToggleSearchIcon)}
                 />
               </View>
               <View style=Styles.row>
                 <Paragraph> {ReasonReact.string("More icon")} </Paragraph>
                 <Switch
                   value={self.state.showMoreIcon}
                   onValueChange={_event => self.send(ToggleMoreIcon)}
                 />
               </View>
               <Appbar style=Styles.bottomStyle>
                 <Appbar.Action
                   icon={Icon.Name("archive")}
                   onPress={_event => ()}
                 />
                 <Appbar.Action
                   icon={Icon.Name("mail")}
                   onPress={_event => ()}
                 />
                 <Appbar.Action
                   icon={Icon.Name("label")}
                   onPress={_event => ()}
                 />
                 <Appbar.Action
                   icon={Icon.Name("delete")}
                   onPress={_event => ()}
                 />
               </Appbar>
               <FAB
                 icon={Icon.Name("reply")}
                 onPress={_event => ()}
                 style=Styles.fab
               />
             </View>
         }
    </StackNavigator.Screen>,
};
