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

type checkboxState =
  | Checked
  | Unchecked
  | Indeterminate;

type state = {
  enabled: checkboxState,
  androidEnabled: checkboxState,
  iosEnabled: checkboxState,
};

type action =
  | ToggleCheckbox(checkboxState)
  | ToggleCheckboxAndroid(checkboxState)
  | ToggleCheckboxIOS(checkboxState);

let component = ReasonReact.reducerComponent("Checkbox Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {
    enabled: Checked,
    androidEnabled: Checked,
    iosEnabled: Checked,
  },
  reducer: (action, state) =>
    switch (action) {
    | ToggleCheckbox(checkboxState) =>
      ReasonReact.Update({...state, enabled: checkboxState})
    | ToggleCheckboxAndroid(checkboxState) =>
      ReasonReact.Update({...state, androidEnabled: checkboxState})
    | ToggleCheckboxIOS(checkboxState) =>
      ReasonReact.Update({...state, iosEnabled: checkboxState})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Checkbox example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <TouchableRipple
                 onPress={
                   _event =>
                     self.send(
                       ToggleCheckbox(
                         switch (self.state.enabled) {
                         | Checked => Unchecked
                         | Unchecked => Indeterminate
                         | Indeterminate => Checked
                         },
                       ),
                     )
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("Checkbox")} </Text>
                   <View pointerEvents=`none>
                     <Checkbox
                       status={
                         switch (self.state.enabled) {
                         | Checked => `checked
                         | Unchecked => `unchecked
                         | Indeterminate => `indeterminate
                         }
                       }
                     />
                   </View>
                 </View>
               </TouchableRipple>
               <View style=Styles.row>
                 <Text> {ReasonReact.string("Disabled on")} </Text>
                 <Checkbox disabled=true status=`checked />
               </View>
               <View style=Styles.row>
                 <Text> {ReasonReact.string("Disabled off")} </Text>
                 <Checkbox disabled=true status=`unchecked />
               </View>
               <View style=Styles.row>
                 <Text> {ReasonReact.string("Disabled indeterminate")} </Text>
                 <Checkbox disabled=true status=`indeterminate />
               </View>
               <TouchableRipple
                 onPress={
                   _event =>
                     self.send(
                       ToggleCheckboxAndroid(
                         switch (self.state.androidEnabled) {
                         | Checked => Unchecked
                         | Unchecked => Indeterminate
                         | Indeterminate => Checked
                         },
                       ),
                     )
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("Checkbox.Android")} </Text>
                   <View pointerEvents=`none>
                     <Checkbox.Android
                       status={
                         switch (self.state.androidEnabled) {
                         | Checked => `checked
                         | Unchecked => `unchecked
                         | Indeterminate => `indeterminate
                         }
                       }
                     />
                   </View>
                 </View>
               </TouchableRipple>
               <TouchableRipple
                 onPress={
                   _event =>
                     self.send(
                       ToggleCheckboxIOS(
                         switch (self.state.iosEnabled) {
                         | Checked => Unchecked
                         | Unchecked => Indeterminate
                         | Indeterminate => Checked
                         },
                       ),
                     )
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("Checkbox.IOS")} </Text>
                   <View pointerEvents=`none>
                     <Checkbox.IOS
                       status={
                         switch (self.state.iosEnabled) {
                         | Checked => `checked
                         | Unchecked => `unchecked
                         | Indeterminate => `indeterminate
                         }
                       }
                     />
                   </View>
                 </View>
               </TouchableRipple>
             </View>
         }
    </StackNavigator.Screen>,
};
