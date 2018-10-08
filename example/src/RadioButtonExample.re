open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0)]);

  let row =
    style([
      flexDirection(Row),
      justifyContent(SpaceBetween),
      alignItems(Center),
      padding(Pt(16.)),
    ]);
};

type radioButtonState =
  | FirstEnabled
  | SecondEnabled;

type state = {
  enabled: radioButtonState,
  androidEnabled: bool,
  iosEnabled: bool,
};

type action =
  | ToggleRadioButton(radioButtonState)
  | ToggleRadioAndroid(bool)
  | ToggleRadioIOS(bool);

let component = ReasonReact.reducerComponent("RadioButton Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {
    enabled: FirstEnabled,
    androidEnabled: true,
    iosEnabled: true,
  },
  reducer: (action, state) =>
    switch (action) {
    | ToggleRadioButton(enabled) => ReasonReact.Update({...state, enabled})
    | ToggleRadioAndroid(enabled) =>
      ReasonReact.Update({...state, androidEnabled: enabled})
    | ToggleRadioIOS(enabled) =>
      ReasonReact.Update({...state, iosEnabled: enabled})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="RadioButton example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <TouchableRipple
                 onPress={
                   _event => self.send(ToggleRadioButton(FirstEnabled))
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("RadioButton 1")} </Text>
                   <View pointerEvents=`none>
                     <RadioButton
                       status={
                         switch (self.state.enabled) {
                         | FirstEnabled => `checked
                         | SecondEnabled => `unchecked
                         }
                       }
                       value="first"
                     />
                   </View>
                 </View>
               </TouchableRipple>
               <TouchableRipple
                 onPress={
                   _event => self.send(ToggleRadioButton(SecondEnabled))
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("RadioButton 2")} </Text>
                   <View pointerEvents=`none>
                     <RadioButton
                       status={
                         switch (self.state.enabled) {
                         | FirstEnabled => `unchecked
                         | SecondEnabled => `checked
                         }
                       }
                       value="second"
                     />
                   </View>
                 </View>
               </TouchableRipple>
               <View style=Styles.row>
                 <Text> {ReasonReact.string("Disabled on")} </Text>
                 <RadioButton disabled=true status=`checked value="first" />
               </View>
               <View style=Styles.row>
                 <Text> {ReasonReact.string("Disabled off")} </Text>
                 <RadioButton disabled=true status=`unchecked value="second" />
               </View>
               <TouchableRipple
                 onPress={
                   _event =>
                     self.send(
                       ToggleRadioAndroid(!self.state.androidEnabled),
                     )
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("RadioButton.Android")} </Text>
                   <View pointerEvents=`none>
                     <RadioButton.Android
                       status={
                         switch (self.state.androidEnabled) {
                         | false => `unchecked
                         | true => `checked
                         }
                       }
                       value="second"
                     />
                   </View>
                 </View>
               </TouchableRipple>
               <TouchableRipple
                 onPress={
                   _event =>
                     self.send(ToggleRadioIOS(!self.state.iosEnabled))
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("RadioButton.IOS")} </Text>
                   <View pointerEvents=`none>
                     <RadioButton.IOS
                       status={
                         switch (self.state.iosEnabled) {
                         | false => `unchecked
                         | true => `checked
                         }
                       }
                       value="second"
                     />
                   </View>
                 </View>
               </TouchableRipple>
             </View>
         }
    </StackNavigator.Screen>,
};
