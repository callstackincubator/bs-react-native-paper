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

type state = {enabled: bool};

type action =
  | ToggleSwitch(bool);

let component = ReasonReact.reducerComponent("Switch Example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {enabled: true},
  reducer: (action, _state) =>
    switch (action) {
    | ToggleSwitch(enabled) => ReasonReact.Update({enabled: enabled})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Switch example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <TouchableRipple
                 onPress={
                   _event => self.send(ToggleSwitch(!self.state.enabled))
                 }>
                 <View style=Styles.row>
                   <Text> {ReasonReact.string("Enabled")} </Text>
                   <View pointerEvents=`none>
                     <Switch value={self.state.enabled} />
                   </View>
                 </View>
               </TouchableRipple>
               <View style=Styles.row>
                 <Text> {ReasonReact.string("Disabled on")} </Text>
                 <Switch value=true disabled=true />
               </View>
               <View style=Styles.row>
                 <Text> {ReasonReact.string("Disabled off")} </Text>
                 <Switch value=false disabled=true />
               </View>
             </View>
         }
    </StackNavigator.Screen>,
};
