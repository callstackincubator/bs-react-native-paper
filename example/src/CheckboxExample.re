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

type state = {
  enabled: Checkbox.status,
  androidEnabled: Checkbox.status,
  iosEnabled: Checkbox.status,
};

type action =
  | ToggleCheckbox(Checkbox.status)
  | ToggleCheckboxAndroid(Checkbox.status)
  | ToggleCheckboxIOS(Checkbox.status);

let component = ReasonReact.reducerComponent("Checkbox Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {
    enabled: `checked,
    androidEnabled: `checked,
    iosEnabled: `checked,
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
                         | `checked => `unchecked
                         | `unchecked => `indeterminate
                         | `indeterminate => `checked
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
                         | `checked => `unchecked
                         | `unchecked => `indeterminate
                         | `indeterminate => `checked
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
                         | `checked => `unchecked
                         | `unchecked => `indeterminate
                         | `indeterminate => `checked
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
                         | `checked => `unchecked
                         | `unchecked => `indeterminate
                         | `indeterminate => `checked
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
                         | `checked => `unchecked
                         | `unchecked => `indeterminate
                         | `indeterminate => `checked
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
                         | `checked => `unchecked
                         | `unchecked => `indeterminate
                         | `indeterminate => `checked
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
