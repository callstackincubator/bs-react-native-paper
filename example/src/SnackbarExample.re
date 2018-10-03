open BsReactNative;
open Navigation;

module Styles = {
  open Style;

  let container =
    style([flex(1.0), justifyContent(Center), alignItems(Center)]);
};

type state = {visible: bool};

type action =
  | ToggleVisible(bool);

let component = ReasonReact.reducerComponent("SnackbarExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {visible: false},
  reducer: (action, _state) =>
    switch (action) {
    | ToggleVisible(visible) => ReasonReact.Update({visible: visible})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Snackbar example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Paper.Button
                 mode=`outlined
                 onPress={
                   _event => self.send(ToggleVisible(!self.state.visible))
                 }>
                 {ReasonReact.string("Press me")}
               </Paper.Button>
               <Paper.Snackbar
                 onDismiss={() => self.send(ToggleVisible(false))}
                 duration=Paper.Snackbar.DurationLong
                 visible={self.state.visible}
                 action={
                   Paper.Snackbar.snackbarAction(
                     ~label="Press me", ~onPress=() =>
                     self.send(ToggleVisible(!self.state.visible))
                   )
                 }>
                 {ReasonReact.string("This is snackbar")}
               </Paper.Snackbar>
             </View>
         }
    </StackNavigator.Screen>,
};
