open BsReactNative;
open Navigation;
open BsReactNativePaper;
open Paper;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.0),
      padding(Pt(16.)),
      backgroundColor(String("#ededed")),
    ]);
};

type state = {
  visibleLongText: bool,
  visibleLoadingIndicator: bool,
  visibleUndismissableDialog: bool,
  visibleRadioButtons: bool,
  visibleCustomColors: bool,
};

type action =
  | ChangeVisibleLongText(bool)
  | ChangeVisibleLoadingIndicator(bool)
  | ChangeVisibleUndismissableDialog(bool)
  | ChangeVisibleCustomColors(bool)
  | ChangeVisibleRadioButtons(bool);

let component = ReasonReact.reducerComponent("DialogExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {
    visibleLongText: false,
    visibleLoadingIndicator: false,
    visibleUndismissableDialog: false,
    visibleRadioButtons: false,
    visibleCustomColors: false,
  },
  reducer: (action, state) =>
    switch (action) {
    | ChangeVisibleLongText(visible) =>
      ReasonReact.Update({...state, visibleLongText: visible})
    | ChangeVisibleLoadingIndicator(visible) =>
      ReasonReact.Update({...state, visibleLoadingIndicator: visible})
    | ChangeVisibleUndismissableDialog(visible) =>
      ReasonReact.Update({...state, visibleUndismissableDialog: visible})
    | ChangeVisibleCustomColors(visible) =>
      ReasonReact.Update({...state, visibleCustomColors: visible})
    | ChangeVisibleRadioButtons(visible) =>
      ReasonReact.Update({...state, visibleRadioButtons: visible})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Dialog example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Button
                 onPress={_event => self.send(ChangeVisibleLongText(true))}>
                 {ReasonReact.string("Show dialog with long text")}
               </Button>
               <Button
                 onPress={
                   _event => self.send(ChangeVisibleRadioButtons(true))
                 }>
                 {ReasonReact.string("Show dialog with radio buttons")}
               </Button>
               <Button
                 onPress={
                   _event => self.send(ChangeVisibleLoadingIndicator(true))
                 }>
                 {ReasonReact.string("Show dialog with loading indicator")}
               </Button>
               <Button
                 onPress={
                   _event =>
                     self.send(ChangeVisibleUndismissableDialog(true))
                 }>
                 {ReasonReact.string("Show undismisable dialog")}
               </Button>
               <Button
                 onPress={
                   _event => self.send(ChangeVisibleCustomColors(true))
                 }>
                 {ReasonReact.string("Show dialog with custom colors")}
               </Button>
               <DialogWithLoadingIndicator
                 visible={self.state.visibleLoadingIndicator}
                 close={
                   () => self.send(ChangeVisibleLoadingIndicator(false))
                 }
               />
               <DialogWithLongText
                 visible={self.state.visibleLongText}
                 close={() => self.send(ChangeVisibleLongText(false))}
               />
               <DialogWithRadioButtons
                 visible={self.state.visibleRadioButtons}
                 close={() => self.send(ChangeVisibleRadioButtons(false))}
               />
               <UndismissableDialog
                 visible={self.state.visibleUndismissableDialog}
                 close={
                   () => self.send(ChangeVisibleUndismissableDialog(false))
                 }
               />
               <DialogWithCustomColors
                 visible={self.state.visibleCustomColors}
                 close={() => self.send(ChangeVisibleCustomColors(false))}
               />
             </View>
         }
    </StackNavigator.Screen>,
};
